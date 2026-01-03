from os.path import exists
from psutil import disk_usage

from functions_for_scan import *

def scan_drives_windows() -> None:
	local_drives: list[str] = []

	for drive in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
		if exists(f"{drive}:"):
			local_drives.append(drive)
		#end if
	#end for

	detected_drives = {}

	for drive in local_drives:
		# append :\ after volume name
		drive += ":\\"
		disk = disk_usage(drive)

		detected_drives[drive] = {
			"total" : human_readable_size(disk.total),
			"used" : human_readable_size(disk.used),
			"free" : human_readable_size(disk.free),
			"percentage" : f"{free_space_left(disk.total, disk.free):.2f} %"
		}
	#end for

	for current_drive in detected_drives.items():
		print(current_drive)
	#end for
#end function