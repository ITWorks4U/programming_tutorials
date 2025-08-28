from os.path import exists
from psutil import disk_usage

from functions_for_scan import *

_local_drives: list[str] = []

def _scan_drives() -> None:
	for drive in "ABCDEFGHIJKLMNOPQRSTUVWXYZ":
		if exists(f"{drive}:"):
			_local_drives.append(drive)
		#end if
	#end for
#end function

def scan_drives_windows() -> None:
	_scan_drives()

	for drive in _local_drives:
		# append :\ after volume name
		d = drive + ":\\"
		print(f"current drive: {d}")

		disk = disk_usage(d)

		summary: dict[str,str] = {
			"total" : human_readable_size(disk.total),
			"used" : human_readable_size(disk.used),
			"free" : human_readable_size(disk.free)
		}

		print(summary)

		print_free_space_left(disk.total, disk.free)
	#end for
#end function