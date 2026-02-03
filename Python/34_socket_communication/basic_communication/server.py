# ---
# server, which is listening for a single client and
# repeats the client's message
# ---

from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
from select import select

from config.constants import SocketConstants
from div.log_events import LogEvent, LogType
from div.signal_handling import SignalHandler

def start_server(le: LogEvent) -> None:
	le.log_into_file("establish a server connection...")

	try:
		# NOTE:
		#       AF_INET      := only for IPv4
		#       AF_INET6     := only for IPv6
		#
		#       SOCK_STREAM  := TCP connection
		#       SOL_SOCKET   := this socket connection belongs to the socket itself
		#                       (not for TCP or IP)
		#       SO_REUSEADDR := allows you to reuse this address to avoid "address already in use" error

		with socket(AF_INET, SOCK_STREAM) as s:
			sc: SocketConstants = SocketConstants()

			# allow for quick reuse
			s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

			# bind the host name and port number
			# NOTE: a tuple is required here, so host_name
			# and port_number are members of a tuple

			bind_address: tuple[str] = (sc.host_name, sc.port_number)
			s.bind(bind_address)

			# start to listen to that connection
			s.listen()

			le.log_into_file(f"[server] listening on {sc.host_name}/32:{sc.port_number}")

			while True:
				# listening with a timeout of 1 second
				# NOTE: it also takes 1 second when a SIGINT (CTRL + C) has been fired
				# NOTE: the select function takes no keyword arguments
				ready_to_read, _, _ = select([s], [], [], 1.0)

				if s in ready_to_read:
					# listen from a client connection
					socket_conn, ret_addr = s.accept()

					with socket_conn:
						le.log_into_file(f"[server] connected by {ret_addr}")

						while True:
							data: bytes = socket_conn.recv(sc.buffer_size)

							if not data:
								le.log_into_file(f"[server] connection to client {ret_addr} lost", log_type=LogType.WARNING_TYPE)
								break
							#end if

							msg: str = data.decode()
							le.log_into_file(f"[server] received message: {msg} <=> {len(msg)}")

							# echo the message back to the sender, if any
							if len(msg) > 0:
								socket_conn.sendall(data)
								le.log_into_file(f"[server] echoed message back to {ret_addr}")
							#end if
						#end while
					#end with
				#end if
			#end while
		#end with
	except Exception as e:
		le.log_into_file(f"error: {e.args}", log_type=LogType.ERROR_TYPE)
	finally:
		le.log_into_file(f"server ({sc.host_name}/32:{sc.port_number}) shut down")
	#end try
#end function

if __name__ == "__main__":
	server_logger: LogEvent = LogEvent(log_file_name="server.log")
	sh: SignalHandler = SignalHandler(le=server_logger)

	start_server(le=server_logger)
#end entry point