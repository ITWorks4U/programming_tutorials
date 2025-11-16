#pragma once
#include <string>

using String = std::string;

/// @brief Config reader class to provide to read a config file.
class ConfigReader {
	String port_name = "";            // no known port name
	unsigned long baud_rate = 9600UL; // 9600 baud rate by default

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
	/// NOTE:  The config file must have the valid keys: host, port.
	/// @param config_path a valid config path
	ConfigReader(String config_path) {
		load_config_file(config_path);
	}

	virtual ~ConfigReader() {}

	// getters

	/// @brief Returns the port name.
	String get_port_name() const;

	/// @brief Returns the used baud rate.
	unsigned long get_baud_rate() const;
};