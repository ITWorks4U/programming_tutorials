# ---
# Just an abstract class for the system information classes.
# ---

from abc import ABC, abstractmethod

class SystemInformation(ABC):
	# ---
	# abstract methods
	# ---

	@abstractmethod
	def _analyze_cpu(self):
		"""
		Figure out and return which processor name can be determined.
		"""
		pass
	#end method

	@abstractmethod
	def _get_cpu_temperature(self):
		"""
		Return the CPU temperature.

		**NOTE:** Not every system can provide
		the current CPU temperature.
		"""
		pass
	#end method

	# ---
	# internal class methods
	# ---

	def _cpu_loadout(self) -> dict[str, str]:
		"""
		Return the current CPU usages depending on how many
		processes are now running on your system.
		"""
		from psutil import getloadavg
		from os import cpu_count

		load1, load2, load3 = getloadavg()
		nbr_of_cpu_cores = cpu_count()

		return {
			"load 1" : f"{load1 / nbr_of_cpu_cores * 100:.5} %",
			"load 2" : f"{load2 / nbr_of_cpu_cores * 100:.5} %",
			"load 3" : f"{load3 / nbr_of_cpu_cores * 100:.5} %"
		}
	#end method

	def _human_readable_size(self, byte_size: int) -> str:
		"""
		Transform byte size into a clean human readable value.

		byte_size:

		-	the size in bytes

		returns:

		-	the converted bytes into a more clean human readable value
		"""
		# sizes                                     bytes
		KBYTES = float(1024)                      # 1,024
		MBYTES = (KBYTES ** 2)                    # 1,048,576
		GBYTES = (KBYTES ** 3)                    # 1,073,741,824
		TBYTES = (KBYTES ** 4)                    # 1,099511628e12

		if byte_size < KBYTES:
			return f"{byte_size} Bytes" if (byte_size == 0 or byte_size > 1) else "Byte"
		elif byte_size >= KBYTES and byte_size < MBYTES:
			return f"{byte_size / KBYTES:.2f} KB"
		elif byte_size >= MBYTES and byte_size < GBYTES:
			return f"{byte_size / MBYTES:.2f} MB"
		elif byte_size >= GBYTES and byte_size < TBYTES:
			return f"{byte_size / GBYTES:.2f} GB"
		#end if

		return f"{byte_size / TBYTES:.2f} TB"
	#end method

	def _analyze_gpu_usage(self) -> list[dict[str, str]]:
		"""
		Return the GPU usage, GPU RAM, etc, depending on
		which GPU has been detected on your system, if any.

		**NOTE:** Make sure you have installed the GPUtil
		package, otherwise an error appears on runtime.
		"""
		from GPUtil import getGPUs
		detected_gpus: list[dict[str, str]] = []

		for ctr, sub_gpu in enumerate(getGPUs()):
			# NOTE: memoryTotal, memoryFree, memoryUsed usually returns the total size in MB
			ctr += 1

			detected_gpus.append({
				f"(GPU {ctr})" : "",
				f"(GPU {ctr}) name" : f"{sub_gpu.name}",
				f"(GPU {ctr}) driver" : f"{sub_gpu.driver}",
				f"(GPU {ctr}) temperature" : f"{sub_gpu.temperature} °C",
				f"(GPU {ctr}) GPU RAM" : f"{sub_gpu.memoryTotal} MB",
				f"(GPU {ctr}) GPU RAM in use" : f"{sub_gpu.memoryUsed} MB",
				f"(GPU {ctr}) GPU RAM left" : f"{sub_gpu.memoryFree} MB",
				f"(GPU {ctr}) uuid" : f"{sub_gpu.uuid}"
			})
		#end for

		return detected_gpus
	#end method

	def _analyze_ram_usage(self):
		"""
		Return the current RAM, its usage, free space left, ...

		**NOTE:** Not every system offers more detailed informations.
		"""
		from psutil import virtual_memory
		ram = virtual_memory()

		return {
			"RAM total" : self._human_readable_size(ram[0]),
			"RAM available" : self._human_readable_size(ram[1]),
			"RAM in use (%)" : f"{ram[2]} %",
			"RAM in use" : self._human_readable_size(ram[3])
		}
	#end method
#end class