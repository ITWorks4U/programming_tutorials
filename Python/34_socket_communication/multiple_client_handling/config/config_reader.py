from div.log_events import LogEvent, LogType

class ConfigReader:
	def __init__(self, le: LogEvent) -> None:
		# fallback settings, if the config file was unable
		# to read or else
		self.host_name: str = "localhost"
		self.port_number: int = 12345
		self.buffer_size: int = 1024

		# expected section name in config file
		self._section_name: str = "socket"

		self._read_config_file(log_instance=le)
	#end constructor

	@property
	def socket_settings(self) -> tuple:
		#NOTE: port number and buffer size must be integers
		return self.host_name, int(self.port_number), int(self.buffer_size)
	#end property

	def _read_config_file(self, log_instance: LogEvent, config_file_name: str = "connection.ini") -> None:
		from os.path import join, dirname, isfile
		from configparser import ConfigParser

		cfg_path = join(dirname(__file__), config_file_name)

		if not isfile(cfg_path):
			log_instance.log_into_file(
				f"error: Expected config file '{config_file_name}' not found. Using default settings instead.",
				log_type=LogType.ERROR_TYPE
			)
			return
		#end if

		cfg: ConfigParser = ConfigParser()

		cfg.read(cfg_path)
		all_settings: dict[str, str] = {section: dict(cfg[section]) for section in cfg.sections()}

		if not self._section_name in all_settings:
			log_instance.log_into_file(
				f"error: Expected section '{self._section_name}' in config file '{config_file_name}' not found. Using default settings instead.",
				log_type=LogType.ERROR_TYPE
			)
			return
		#end if

		socket_settings: dict[str, str] = all_settings[self._section_name]
		self.host_name = socket_settings["host_name"]
		self.port_number = socket_settings["port_number"]
		self.buffer_size = socket_settings["buffer_size"]

		# check, if host or port might be unset
		if self.host_name == "" or self.port_number == "":
			log_instance.log_into_file(
				f"error: host name or port number not found. Using default settings instead.",
				log_type=LogType.ERROR_TYPE
			)
		#end if
	#end method
#end class