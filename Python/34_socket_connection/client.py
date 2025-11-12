# ---
# client, which starts a connection to the server
# ---

from sys import stderr
from socket import AF_INET, SOCK_STREAM, socket

from constants import SocketConstants
import signal_handling as sig

def start_client() -> None:
	try:
		# NOTE: AF_INET is only for IPv4. If IPv6 is planned to use,
		#       AF_INET6 shall be used instead.

		with socket(AF_INET, SOCK_STREAM) as s:
			sc: SocketConstants = SocketConstants()

			s.connect((sc.host_name, sc.port_number))
			print(f"[client] connection to {sc.host_name}/32:{sc.port_number} established")
			print(f"[client] terminate the connection by 'q'")

			while True:
				msg: str = input("enter a message to send: ")

				if msg == "q":
					break
				#end if

				# NOTE: sendall() does not mean: "send to all servers/clients"
				# this is optimized for TCP connection and tells:
				# send the full message by TCP to the destination connection
				s.sendall(msg.encode())

				echo_data: bytes = s.recv(sc.buffer_size)
				print(f"[client] received echo: {echo_data.decode()}")
			#end while
		#end with
	except Exception as e:
		print(f"error: {e.args}", file=stderr)
	#end try
#end function

if __name__ == "__main__":
	sig.register_signals()
	start_client()
#end entry point