class SocketConstants:
	# host name can be an IPv4-address, IPv6-address
	# or also a host name in words
	#
	# NOTE: By default an IPv4-address is going to use.
	#       If you want to use an IPv6-address, make sure
	#       to use AF_INET6 (server.py, line 26 | client.py, line 19) instead.
	host_name: str = "localhost"

	# non privileged port
	# NOTE: A port comes with a range of [0..65,535]
	# NOTE: In theory, a high port number ensures to get a
	#       possible connection without blocking
	#       that port for any other application.
	port_number: int = 12345

	# given buffer size in bytes for communication
	buffer_size: int = 1024
#end class