#pragma once

#include <string>
#include <vector>
#include "config_reader.h"

// required to scan all available
// serial ports
#ifdef _WIN32
// only for Windows
#include <WinSock2.h>
#include <windows.h>
#elif defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
// for an UNIX system
#include <dirent.h>
#endif

// NOTE: Since this header file can be included by -I<path> this
//       "error" can be ignored.
#include "asio.hpp"

using String = std::string;
using Vector = std::vector<String>;

class SerialConnection {
	asio::io_context io_;
	asio::serial_port serial_;
	int timeout_ms_;
	bool ports_existing = false;
	Vector valid_commands = {"system_info", "led_green_on", "led_green_off", "led_yellow_on", "led_yellow_off", "led_red_on", "led_red_off"};

	/// @brief Scan all possible serial ports. Depending on the certain
	/// operating system the port names and the number of ports differs.
	/// @return All possible serial ports or nothing, if no one has been detected.
	Vector scan_ports();

	public:
	/// @brief Create a new serial connection. It may fail on any occurred exception.
	/// @param cfg_reader The config reader class container.
	SerialConnection(const ConfigReader &cfg_reader);

	/// @brief Close the serial connection on destroy, if a serial connection has been opened before.
	virtual ~SerialConnection();

	/// @brief Write a command to send.
	/// @param msg the message to send.
	void write(const String& msg);

	/// @brief Read the response data, if any.
	/// @return the response data, if any
	String read_line();

	/// @brief Read a full data response. More in use for "system_info", because
	/// a multiple line message from the microcontroller will return.
	/// @return the response data, if any
	String read_full_response();

	/// @brief Returns a flag, if serial ports are available.
	bool on_existing_serial_ports() const;

	/// @brief Checks, if the certain input is a valid command for the desired destination device.
	/// @param input the input command to check
	/// @return true, if the command is in the known command collection, otherwise false
	bool on_valid_command(const String input);

	/// @brief Print all available commands to the console.
	void print_all_commands();
};