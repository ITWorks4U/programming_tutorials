# ---
# Read the settings.conf for MQTT.
# ---

class ConfigReaderMQTT:
	_hosts: list[str]
	_ports: list[str]
	_users: dict[str, str]
	_subscriber_channels: list[str]
	_publisher_channels: list[str]
	_file_name = "settings.conf"

	@property
	def host_names(self) -> list[str]:
		"""Get all host names as a list."""
		return self._hosts
	#end property

	@property
	def ports(self) -> list[str]:
		"""
		Get all ports as a list.

		**NOTE:** *The ports are still a string!*
		"""
		return self._ports
	#end property

	@property
	def users(self) -> dict[str, str]:
		"""
		Returning the users and their passwords as a dictionary.

		Each value contains a single user and its certain password.
		"""
		return self._users
	#end property

	@property
	def subscriber_channels(self) -> list[str]:
		"""Get all subscriber channels as a list."""
		return self._subscriber_channels
	#end property

	@property
	def publisher_channels(self) -> list[str]:
		"""Get all publisher channels as a list."""
		return self._publisher_channels
	#end property

	def read_settings(self, cfg_path: str = None) -> None:
		"""
		Read the MQTT settings from the nested settings.conf file.

		---
		**NOTE**:
		The settings.conf comes with a clean description of how to use
		the settings in the correct way.

		Otherwise an error anywhere is going to raise.

		---
		raises:
		- raises FileNotFoundError, if the config file was not found
		- raises Exception, if a required key (user or host) in the settings.conf was not set
		- raises Exception, if the user (users=) is **not** in form of (a:b)
		"""
		from os.path import join, dirname, isfile
		from configparser import ConfigParser

		config = ConfigParser()

		# NOTE: By default the Python interpreter is still unable to
		# find the file, which exists, so this must be handled by hand.
		if cfg_path is None:
			cfg_path = join(dirname(__file__), self._file_name)
		#end if

		if not isfile(cfg_path):
			raise FileNotFoundError(f"Config file {self._file_name} was not found.")
		#end if

		config.read(cfg_path)

		# config returns here a single dictionray with: {"mqtt" : "<everything from the settings.conf file as one value>"}
		temp: dict[str, str] = {section: dict(config[section]) for section in config.sections()}

		# so we just need to extract the "mqtt" key only
		settings: dict[str, str] = dict(temp["mqtt"])

		# collect all required data
		# NOTE: _hosts, _ports, _subscriber_channels, _publisher_channels
		# can either contain at least one real data or are set to None
		# in case of no valid information from the config file was able to use
		# NOTE: on multiple hosts, ports, publish or subscription channels make sure not to add
		# any leading or trailing space(s), newline(s) by using strip()
		self._hosts = self._on_empty_list_value([host.strip() for host in settings["hosts"].split(",")])
		self._ports = self._on_empty_list_value([port.strip() for port in settings["ports"].split(",")])
		self._subscriber_channels = self._on_empty_list_value([channel.strip() for channel in settings["subscriber_channels"].split(",")])
		self._publisher_channels = self._on_empty_list_value([channel.strip() for channel in settings["publisher_channels"].split(",")])

		# check, if a user:password pair is given
		user_passwords = self._on_empty_list_value(settings["users"].split(","))

		if user_passwords:
			# ---
			# NOTE: The users are covered by (word:word), where: "(" , ")" must be removed,
			# followed by replacing ":" with ",", which can be converted into a dictionary
			from re import findall
			filter_regex: str = r"\(([^:]+):([^)]+)\)"
			user_passwd_pairs = [findall(filter_regex, element)[0] for element in settings["users"].split(",")]
			self._users = dict(user_passwd_pairs)
			# ---
		#end if

		# final check, if a required key is missing
		missing_collection = {
			"hosts" : self._hosts,
			"ports" : self._ports
		}

		if None in missing_collection.values():
			raise Exception("Missing required setting(s): host or port")
		#end if
	#end method

	def _on_empty_list_value(self, list_property: list[str]) -> list[str] | None:
		"""
		Checks, if a list may not contain anything.
		This happens, when in the settings.conf nothing behind a
		key is given. The list only contains [""], which is equal
		to "nothing".

		If the list is "empty" or real empty, then **None** returns,
		otherwise the list itself.

		---
		list_property:
		- a list for the MQTT settings

		returns:
		- the list itself, if this is not "empty" or real empty,
		- otherwise None
		"""
		if len(list_property) == 0 or list_property == [""]:
			return None
		#end if

		return list_property
#end class