from os import listdir
from psutil import disk_usage, disk_partitions
from functions_for_scan import *

def _on_physical_device(part) -> bool:
	"""
	Check, if the current path part is a physical device.
	This is only given, if this is not tmpfs or udev.

	part:
		-	current path part

	returns:
		-	True, if this is a physical device
		-	False, otherwise
	"""

	is_tmpfs = part.fstype.startswith("tmpfs")
	is_udev = part.device.startswith("udev")

	return not (is_tmpfs or is_udev)
#end function

def scan_drives_unix() -> None:
	"""
	Scan some drives on any UNIX system, like Linux, macOS.
	Not all drives may exist.
	"""
	print("NOTE: Some paths could be unable to scan without root settings.", end="\n\n")
	paths = [part.mountpoint for part in disk_partitions() if _on_physical_device(part)]

	detected_drives = {}
	failed_scans = []

	for current_path in paths:
		try:
			for d in listdir(current_path):
				current_folder: str = current_path + d

				disk = disk_usage(current_folder)

				detected_drives[current_folder] = {
					"total" : human_readable_size(disk.total),
					"used" : human_readable_size(disk.used),
					"free" : human_readable_size(disk.free),
					"percentage" : f"{free_space_left(disk.total, disk.free):.2f} %"
				}
			#end for
		except Exception as e:
			failed_scans.append(f"{current_path}: {e.args}")
		#end try
	#end for

	for current_drive in detected_drives.items():
		print(current_drive)
	#end for

	if len(failed_scans) > 0:
		print("-----------")
		for f in failed_scans:
			print(f)
		#end for
	#end if
#end function