# Scan the drive folders from a certain root path.
# Works for Windows, Linux and possibly for macOS (never tested)
#
# required installed api: psutil
# pip[3|.exe] install psutil

from platform import system
from scan_drives_linux import scan_drives_unix
from scan_drives_windows import scan_drives_windows

def main() -> None:
	detected_system: str = system()

	function_start = {
		"Windows" : scan_drives_windows,
		"Linux" : scan_drives_unix,
		"Darwin" : scan_drives_unix
	}.get(detected_system, None)

	if not function_start:
		raise Exception(f"unsupported OS: {detected_system} detected...")
	#end if

	# call the scan function depending on
	# the detected system
	function_start()
#end main

if __name__ == "__main__":
	main()
#end entry point