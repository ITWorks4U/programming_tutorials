from os import listdir
from os.path import exists
from psutil import disk_usage, disk_partitions
from functions_for_scan import *

def _is_physical_device(part) -> bool:
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

	print("scan local paths...")
	paths = [part.mountpoint for part in disk_partitions() if _is_physical_device(part)]

	try:
		for current_path in paths:
			if not exists(current_path):
				print(f"skip path {current_path}...")
				continue
			#end if

			print(f"current path: {current_path}\n")

			for d in listdir(current_path):
				current_folder: str = current_path + d

				disk = disk_usage(current_folder)
				print(f"current folder: {current_folder}")

				summary: dict[str,str] = {
					"total" : human_readable_size(disk.total),
					"used" : human_readable_size(disk.used),
					"free" : human_readable_size(disk.free)
				}

				print(summary)
				print_free_space_left(disk.total, disk.free)
			#end for
		#end for
	except Exception as e:
		print(f"error: {e.args}")
	#end try
#end function
