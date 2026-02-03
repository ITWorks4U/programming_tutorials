# ---
# client, which starts a connection to the server
# ---
from socket import socket, AF_INET, SOCK_STREAM

from config.constants import SocketConstants
from div.log_events import LogEvent, LogType
from div.signal_handling import SignalHandler

def start_client(le: LogEvent) -> None:
	le.log_into_file("establish a client connection...")

	try:
		# NOTE:
		#       AF_INET      := only for IPv4
		#       AF_INET6     := only for IPv6
		#
		#       SOCK_STREAM  := TCP connection
		with socket(AF_INET, SOCK_STREAM) as s:
			sc: SocketConstants = SocketConstants()
			bind_address: tuple[str] = (sc.host_name, sc.port_number)

			s.connect(bind_address)
			le.log_into_file(f"[client] connection to {sc.host_name}/32:{sc.port_number} established")
			print(f"[client] terminate the connection by 'q'")

			while True:
				msg: str = input("enter a message to send: ")

				if msg == "q":
					le.log_into_file("[client] connection terminated")
					break
				#end if

				# Ways to send a message:
				# - send()     := send a message to the server and return the
				#                 number of sent bytes
				# - sendall()  := similar to send(data), where also some flags may
				#                 be given (for UNIX only, like: MSG_NOSIGNAL
				#                 => prevents to raise a SIGFPE on a closed socket)
				#                 => on Windows this flag is set to 0 (Windows can't handle a SIGFPE)
				# NOTE:           sendall() does not mean: "send to all servers/clients"
				#                 this is optimized for TCP connection and tells:
				#                 send the full message by TCP to the destination connection
				# - sendto()   := send a message to a desired server
				#                 an IPv[4|6]-address and a port number is required
				# - sendfile() := send a whole file to the server and return the
				#                 number of sent bytes

				_ = s.send(msg.encode())
				# s.sendall(msg.encode())
				# s.sendto(msg.encode(), bind_address)
				# _ = s.sendfile(file=None)

				echo_data: bytes = s.recv(sc.buffer_size)
				print(f"[client] received echo: {echo_data.decode()}")
			#end while
		#end with
	except Exception as e:
		le.log_into_file(f"error: {e.args}", log_type=LogType.ERROR_TYPE)
	finally:
		le.log_into_file(f"client ({sc.host_name}/32:{sc.port_number}) shut down")
	#end try
#end function

if __name__ == "__main__":
	client_logger: LogEvent = LogEvent(log_file_name="client.log")
	sh: SignalHandler = SignalHandler(le=client_logger)

	start_client(le=client_logger)
#end entry point