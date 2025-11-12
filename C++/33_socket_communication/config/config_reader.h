/*
* Read the config file and offers a class pattern to work with.
*/

#pragma once
#include <string>

using String = std::string;

/// @brief Config reader class to provide to read a config file.
class ConfigReader {
	String host_name;
	int port_number;

	/// @brief Load the config file. By default the basic config file
	///        connection.ini is in use.
	///
	/// NOTE:  For the basic config file the config folder must also be appended,
	///        to be able to find the config file.
	/// @param file_name the name of the config file itself
	void load_config_file(const String &file_name = "config/connection.ini");

	public:
	/// @brief Default initialization for the config reader.
	ConfigReader() {
		load_config_file();
	}

	/// @brief Initialize the config reader by using a custom config file instead.
	///
	/// NOTE:  The config file must have the valid keys: host, port and buffer.
	/// @param config_path a valid config path
	ConfigReader(String config_path) {
		load_config_file(config_path);
	}

	virtual ~ConfigReader() {}

	// getters

	/// @brief Returns the host name.
	String get_host_name() const;

	/// @brief Returns the port number.
	int get_port_number() const;
};