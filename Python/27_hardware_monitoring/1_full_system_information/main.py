# ---
# Scan your current system for detected hardware, CPU loadouts,
# GPU usage, RAM usage, ...
#
# NOTE: This script does not flawless run on every system, because some
# modules are only required or available on certain systems.
# ---

from platform import system
from sys import stderr

from system_informations_windows import SystemWindows
from system_informations_unix import SystemUNIX

def main() -> None:
	detected_system: str = system()

	instance_module = {
		"Windows" : SystemWindows,
		"Linux" : SystemUNIX,
		"Darwin" : SystemUNIX
	}.get(detected_system)

	if not instance_module:
		print(f"unsupported OS detected: {detected_system}", file=stderr)
	else:
		# use the instance to work depending on
		# the detected system
		s = instance_module()

		for kvp in s.collected_informations.items():
			# for separators
			if kvp[0] in ["-", "--", "---", "----"]:
				print("----")
			else:
				print(f"{kvp[0]}: {kvp[1]}")
			#end if
		#end for
	#end if
#end main

if __name__ == "__main__":
	main()
#end entry point