# ---
# Receive the system informations on a UNIX machine only.
# ---

from platform import (machine, node, release, platform)
from os import (environ, cpu_count, pathsep)
from re import sub
from subprocess import check_output

from abstract_system_informations import SystemInformation

class SystemUNIX(SystemInformation):
	"""
	Scan the detected hardware on a UNIX system, like Linux, macOS, ...
	Every result is going to store into a dictionary.
	"""
	def __init__(self, used_system: str):
		self.used_system = used_system
	#end constructor

	@property
	def basic_informations(self) -> dict[str, str]:
		"""
		Return the collected system informations in form of
		a dictionary, where the key and also the value is a string.
		"""
		return {
			"computer name" : node(),
			"full OS name" : platform(),
			"system release name" : release(),
			"machine" : machine()
		}
	#end property

	@property
	def cpu_informations(self) -> dict[str, str]:
		return {
			"CPU name" : self._analyze_cpu(),
			"CPU cores" : cpu_count(),
			"CPU usages" : self._cpu_loadout(),
			"CPU temperature" : self._get_cpu_temperature()
		}

	@property
	def ram_collection(self) -> dict[str, str]:
		return self._analyze_ram_usage()
	#end property

	@property
	def detected_gpus(self) -> list[dict[str, str]]:
		# GPU (name, driver, temperature, total RAM, used, free, uuid)
		return self._analyze_gpu_usage()
	#end property

	def _analyze_cpu(self) -> str:
		match self.used_system:
			case "Darwin":
				# usually used for macOS
				# NOTE: never tested
				environ["PATH"] = environ["PATH"] + pathsep + "/usr/sbin"

				return str(check_output("sysctl -n machdep.cpu.brand_string").strip())
			case "Linux":
				# usually every Linux system shall
				# be covered here
				# NOTE: not tested on every possible Linux system

				all_informations = check_output("cat /proc/cpuinfo", shell=True).decode().strip()
				for line in all_informations.split("\n"):
					if "model name" in line:
						return sub( ".*model name.*:", "", line,1)
					#end if
				#end for

				return "---"
			case _:
				# any other UNIX system found, which is not "Darwin" or "Linux"
				return "---"
			#end cases
		#end match
	#end method

	def _get_cpu_temperature(self) -> str | None:
		# NOTE: Depending on the used UNIX system the key
		# in sensor_temperatures may be different.
		from psutil import sensors_temperatures

		# sensor: dict[list[tuple]]
		sensor = sensors_temperatures()

		if isinstance(sensor, dict):
			if self._on_raspberry_pi():
				# for a RaspberryPi the key cpu_thermal shall
				# be in the dictionary

				if "cpu_thermal" in sensor:
					return f"{sensor['cpu_thermal'][0].current} °C"
				#end if

				return "----"
			elif "k10temp" in sensor:
				# check, if this key exists in the dictionary instead
				return sensor["k10temp"][0].current
			#end if

			# otherwise return the full dictionary only
			return sensor
		#end if

		# return nothing, if the sensor is not a dictionary
		return None
	#end method

	def _on_raspberry_pi(self) -> bool:
		"""
		Check, if this script runs on a Raspberry Pi.

		returns:

		- True, if this runs on a Raspberry Pi,
		- False, otherwise
		"""

		try:
			import io
			with io.open(file="/sys/firmware/devicetree/base/model") as src:
				if "raspberry pi" in src.read().lower():
					return True
				#end if
			#end with
		except Exception:
			# it may happen, that the path was not correct or the file was not
			# found or the UNIX system is not a raspberry pi
			pass
		#end try

		return False
	#end method
#end class