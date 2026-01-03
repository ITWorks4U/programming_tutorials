# ---
# Scan your current system for detected hardware, CPU loadouts,
# GPU usage, RAM usage, ...
#
# NOTE: This script does not flawless run on every system, because some
# modules are only required or available on certain systems.
# ---

from platform import system

from system_informations_windows import SystemWindows
from system_informations_unix import SystemUNIX

def display_summary(collection) -> None:
	if isinstance(collection, dict):
		# everything left

		for kvp in collection.items():
			# information: value
			print(f"{kvp[0]}: {kvp[1]}")
		#end for
	elif isinstance(collection, list):
		# for GPU only

		if len(collection) > 0:
			for gpu_collection in collection:
				for kvp in gpu_collection.items():
					print(f"{kvp[0]}: {kvp[1]}")
				#end for
			#end for
		else:
			print("no GPU detected")
		#end if
	#end if

	print()
#end function

def main() -> None:
	detected_system: str = system()

	instance_module = {
		"Windows" : SystemWindows,
		"Linux" : SystemUNIX,
		"Darwin" : SystemUNIX
	}.get(detected_system)

	if not instance_module:
		raise Exception(f"unsupported OS detected: {detected_system}")
	#end if

	# use the instance to work depending on
	# the detected system
	s = instance_module(used_system=detected_system)

	print(f"running on system: {detected_system}", end="\n\n")
	display_summary(s.basic_informations)
	display_summary(s.cpu_informations)
	display_summary(s.ram_collection)
	display_summary(s.detected_gpus)
#end main

if __name__ == "__main__":
	main()
#end entry point