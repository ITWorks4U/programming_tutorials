from socket import socket, AF_INET, SOCK_STREAM, SOL_SOCKET, SO_REUSEADDR
from select import select
from sys import path
from os.path import abspath, join, dirname
from threading import Thread

# Append the absolute path of the current file to the system path
# to be able to read the config file and also other
# source files, which are in an another directories.
path.append(abspath(join(dirname(__file__), "..")))

from config.config_reader import ConfigReader
from div.log_events import LogEvent, LogType
from div.signal_handling import SignalHandler

class SocketServer:
	def handle_single_client(self, **settings) -> None:
		logger: LogEvent = settings["logger"]
		connection: socket = settings["connection"]
		addr = settings["addr"]
		buffer: int = settings["buffer"]

		with connection:
			logger.log_into_file(f"[server] client with {addr} connected")

			while True:
				data: bytes = connection.recv(buffer)

				if not data:
					break
				#end if

				msg: str = data.decode()

				# echo the message back to the sender, if any
				if len(msg) > 0:
					connection.sendall(data)
					logger.log_into_file(f"[server] echoed message back to {addr}")
				#end if
			#end while
		#end with

		logger.log_into_file(f"[server] client ({addr}) disconnected")
	#end method

	def start_server(self, le: LogEvent) -> None:
		try:
			_cfg_reader: ConfigReader = ConfigReader(le=le)

			with socket(AF_INET, SOCK_STREAM) as s:
				s.setsockopt(SOL_SOCKET, SO_REUSEADDR, 1)
				bind_address: tuple = (_cfg_reader.socket_settings[0], _cfg_reader.socket_settings[1])

				s.bind(bind_address)
				s.listen()
				le.log_into_file(f"[server] listening on {_cfg_reader.socket_settings[0]}/32:{_cfg_reader.socket_settings[1]}")

				while True:
					ready_to_read, _, _ = select([s], [], [], 1.0)

					if s in ready_to_read:
						socket_conn, ret_addr = s.accept()

						settings: dict = {
							"logger" : le,                              # instance LogEvent class
							"connection" : socket_conn,                 # socket connection
							"addr" : ret_addr,                          # client's return address
							"buffer" : _cfg_reader.socket_settings[2]   # buffer size for communication
						}

						t = Thread(
							target=self.handle_single_client,
							kwargs=settings,
							daemon=True
						)

						t.start()
					#end if
				#end while
			#end with
		except Exception as e:
			le.log_into_file(f"error: {e.args}", log_type=LogType.ERROR_TYPE)
		finally:
			le.log_into_file(f"server ({_cfg_reader.socket_settings[0]}/32:{_cfg_reader.socket_settings[1]}) shut down")
		#end try
	#end method
#end class

if __name__ == "__main__":
	server_logger: LogEvent = LogEvent(log_file_name="server.log")
	sh: SignalHandler = SignalHandler(le=server_logger)

	server: SocketServer = SocketServer()
	server.start_server(le=server_logger)
#end entry point