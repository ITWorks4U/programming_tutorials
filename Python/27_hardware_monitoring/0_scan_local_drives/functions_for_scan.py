def human_readable_size(size: int) -> str:
	"""
	Convert the system size in bytes to
	a human readable size in Bytes, KB, MB, GB, TB.

	size:
		-	size in bytes only
	"""

	# 1,024 bytes = 1KB
	KBYTES = float(1024)

	# 1,048,576 bytes = 1MB
	MBYTES = (KBYTES ** 2)

	# 1,073,741,824 bytes = 1GB
	GBYTES = (KBYTES ** 3)

	# 1,099511628e12 bytes = 1TB
	TBYTES = (KBYTES ** 4)

	if size < KBYTES:
		return f"{size} Bytes" if (size == 0 or size > 1) else "Byte"
	elif size >= KBYTES and size < MBYTES:
		return f"{size / KBYTES:.2f} KB"
	elif size >= MBYTES and size < GBYTES:
		return f"{size / MBYTES:.2f} MB"
	elif size >= GBYTES and size < TBYTES:
		return f"{size / GBYTES:.2f} GB"
	#end if

	return f"{size / TBYTES:.2f} TB"
#end function

def print_free_space_left(total_size: int, space_left: int) -> None:
	"""
	Determine free space left.

	total_size:
		-	known total size of the drive
	space_left:
		-	knwon free space left
	"""

	print("free space left: ", end="")

	if total_size > 0:
		result = (space_left / total_size)

		# print as a human readable value
		print(f"{result * 100:.2f}%")
	else:
		print("0%")
	#end if
#end function