# Scan the drive folders from a certain root path.
# Works for Windows, Linux and possibly for macOS (never tested)
#
# required installed api: psutil
# pip[3|.exe] install psutil

from platform import system
from scanner_unix import scan_drives_unix
from scanner_windows import scan_drives_windows

def main() -> None:
	detected_system: str = system()

	function_start = {
		"Windows" : scan_drives_windows,
		"Linux" : scan_drives_unix,
		"Darwin" : scan_drives_unix
	}.get(detected_system)

	if not function_start:
		raise Exception(f"unsupported OS: {detected_system} detected...")
	#end if

	print(f"running on a {detected_system} system...")

	# call the scan function depending on
	# the detected system
	function_start()
#end main

if __name__ == "__main__":
	main()
#end entry point