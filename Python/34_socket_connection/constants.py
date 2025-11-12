class SocketConstants:
	# host name can be an IPv4 address, IPv6 address
	# or also a host name in words
	host_name: str = "127.0.0.1"

	# non privileged port
	# NOTE: In theory, a high port number ensures to get a
	#       possible connection without blocking
	#       that port for any other application.
	port_number: int = 65432

	# given buffer size in bytes for communication
	buffer_size: int = 1024
#end class