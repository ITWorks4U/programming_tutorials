# ---
# Receive the system informations on a Windows machine only.
# ---

from platform import (system, processor, machine, node, release, platform)
from os import cpu_count

from abstract_system_informations import SystemInformation

class SystemWindows(SystemInformation):
	"""
	Scan the detected hardware on a Windows system.
	Every result is going to store into a dictionary.
	"""
	def __init__(self) -> None:

		self.system_collection: dict[str, str] = {
			"operating system" : system(),
			"computer name" : node(),
			"full OS name" : platform(),
			"system release name" : release(),
			"machine" : machine(),
			"-" : None,
			"CPU name" : self._analyze_cpu(),
			"CPU cores" : cpu_count(),
			"CPU usages" : self._cpu_loadout(),
			"CPU temperature" : self._get_cpu_temperature(),
			"--" : None,
		}

		# ---
		# RAM (total, available, used, free only)
		ram_total, ram_available, ram_used, ram_free = self._analyze_ram_usage()

		ram_dict: dict[str, str] = {
			"RAM total" : ram_total,
			"RAM available" : ram_available,
			"RAM used" : ram_used,
			"RAM free" : ram_free,
			"---" : None
		}

		self.system_collection.update(ram_dict)
		# ---

		# ---
		# GPU (name, driver, temperature, total RAM, used, free, uuid)
		all_gpus = self._analyze_gpu_usage()

		for gpu_dict in all_gpus:
			self.system_collection.update(gpu_dict)
		#end for
		# ---
	#end constructor

	@property
	def collected_informations(self) -> dict[str, str]:
		"""
		Return the collected system informations in form of
		a dictionary, where the key and also the value is a string.
		"""
		return self.system_collection
	#end property

	def _analyze_cpu(self) -> str:
		return processor()
	#end method

	def _get_cpu_temperature(self) -> str:
		# NOTE: This may not work on every Windows system or the CPU temperature was unable to determine
		#       or a wrong temperature has been found instead.
		#
		# This could also be handled by using some third party applications or by
		# writing an won C/C++/C# library, which is going to use for Python.
		try:
			from wmi import WMI

			w = WMI(namespace="root\\WMI")
			temperature_info = w.MSAcpi_ThermalZoneTemperature()

			for sensor in temperature_info:
				temp_celsius = (sensor.CurrentTemperature / 10.0) - 273.15
				return f"{round(temp_celsius, 2)} °C"
			#end for
		except Exception:
			# e, g.:
			# wmi module has not been installed => pip.exe install wmi, pywin32
			# restricted access or unable to find a way to determine the CPU core temperature
			pass
		finally:
			return "---"
		#end try
	#end method
#end class