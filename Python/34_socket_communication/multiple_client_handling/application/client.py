from socket import socket, AF_INET, SOCK_STREAM
from sys import path
from os.path import abspath, join, dirname

# Append the absolute path of the current file to the system path
# to be able to read the config file and also other
# source files, which are in an another directories.
path.append(abspath(join(dirname(__file__), "..")))

from config.config_reader import ConfigReader
from div.log_events import LogEvent, LogType
from div.signal_handling import SignalHandler

class SocketClient:
	def start_client(self, le: LogEvent) -> None:
		le.log_into_file("establish a client connection...")
		_cfg_reader: ConfigReader = ConfigReader(le=le)

		try:
			with socket(AF_INET, SOCK_STREAM) as s:
				bind_address: tuple = (_cfg_reader.socket_settings[0], _cfg_reader.socket_settings[1])

				s.connect(bind_address)
				le.log_into_file(f"[client] connection to {_cfg_reader.socket_settings[0]}/32:{_cfg_reader.socket_settings[1]} established")
				print(f"[client] terminate the connection by 'q'")

				while True:
					msg: str = input("enter a message: ")

					if msg == "q":
						le.log_into_file("[client] connection terminated")
						break
					#end if

					_ = s.send(msg.encode())

					echo_data: bytes = s.recv(_cfg_reader.socket_settings[2])
					print(f"[client] received echo: {echo_data.decode()}")
				#end while
			#end with
		except Exception as e:
			le.log_into_file(f"error: {e.args}", log_type=LogType.ERROR_TYPE)
		finally:
			le.log_into_file(f"client ({_cfg_reader.socket_settings[0]}/32:{_cfg_reader.socket_settings[1]}) shut down")
		#end try
	#end method
#end class

if __name__ == "__main__":
	client_logger: LogEvent = LogEvent(log_file_name="client.log")
	sh: SignalHandler = SignalHandler(le=client_logger)

	client: SocketClient = SocketClient()
	client.start_client(le=client_logger)
#end entry point