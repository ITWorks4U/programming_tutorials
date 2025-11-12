# ---
# server, which is listening for a single client and
# repeats the client's message
# ---

from sys import stderr
from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
from select import select
from time import sleep

from constants import SocketConstants
import signal_handling as sig

def start_server() -> None:
	try:
		# NOTE: AF_INET is only for IPv4. If IPv6 is planned to use,
		#       AF_INET6 shall be used instead.

		with socket(AF_INET, SOCK_STREAM) as s:
			sc: SocketConstants = SocketConstants()

			# allow for quick reuse
			s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)

			# bind the host name and port number
			# NOTE: a tuple is required here, so host_name
			# and port_number are members of a tuple

			bind_address = (sc.host_name, sc.port_number)
			s.bind(bind_address)

			# start to listen to that connection
			s.listen()

			print(f"[server] listening on {sc.host_name}/32:{sc.port_number}")

			while True:
				# listening with a timeout of 1 second
				# NOTE: it also takes 1 second when a SIGINT (CTRL + C) has been fired
				# NOTE: the select function takes no keyword arguments
				ready_to_read, _, _ = select([s], [], [], 1.0)

				if s in ready_to_read:
					# listen from a client connection
					socket_conn, ret_addr = s.accept()

					with socket_conn:
						print(f"[server] connected by {ret_addr}")

						while True:
							data: bytes = socket_conn.recv(sc.buffer_size)

							if not data:
								print(f"[server] error: connection to client {ret_addr} lost")
								break
							#end if

							msg: str = data.decode()
							print(f"[server] received message: {msg} <=> {len(msg)}")

							# echo the message back to the sender, if any
							if len(msg) > 0:
								socket_conn.sendall(data)
							#end if
						#end while
					#end with
				#end if
		#end with
	except Exception as e:
		print(f"error: {e.args}", file=stderr)
	#end try
#end function

if __name__ == "__main__":
	sig.register_signals()
	start_server()
#end entry point