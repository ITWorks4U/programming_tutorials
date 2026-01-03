def human_readable_size(size_in_bytes: int) -> str:
	"""
	Convert the system size in bytes to
	a human readable size in Bytes, KB, MB, GB, TB.

	size_in_bytes:
		-	size in bytes only

	return:
		-	the calculated size in Bytes, KB, MB, GB or TB
	"""

	# sizes                                     bytes
	KBYTES = float(1024)                      # 1,024
	MBYTES = (KBYTES ** 2)                    # 1,048,576
	GBYTES = (KBYTES ** 3)                    # 1,073,741,824
	TBYTES = (KBYTES ** 4)                    # 1,099511628e12

	if size_in_bytes < KBYTES:
		return f"{size_in_bytes} Bytes" if (size_in_bytes == 0 or size_in_bytes > 1) else "Byte"
	elif size_in_bytes >= KBYTES and size_in_bytes < MBYTES:
		return f"{size_in_bytes / KBYTES:.2f} KB"
	elif size_in_bytes >= MBYTES and size_in_bytes < GBYTES:
		return f"{size_in_bytes / MBYTES:.2f} MB"
	elif size_in_bytes >= GBYTES and size_in_bytes < TBYTES:
		return f"{size_in_bytes / GBYTES:.2f} GB"
	#end if

	return f"{size_in_bytes / TBYTES:.2f} TB"
#end function

def free_space_left(total_size: int, space_left: int) -> float:
	"""
	Determine free space left.

	total_size:
		-	known total size of the drive
	space_left:
		-	knwon free space left
	"""

	if total_size > 0:
		return (space_left / total_size) * 100
	#end if

	return 0.0
#end function