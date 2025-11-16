#include <iostream>
#include <fstream>
#include "config_reader.h"

using namespace std;

// helper function to trim whitespaces
static inline String _trim(const String current_line) {
	size_t start = current_line.find_first_not_of(" \t\r\n");
	size_t end = current_line.find_last_not_of(" \t\r\n");

	if (start == String::npos || end == String::npos) {
		return "";
	}

	return current_line.substr(start, end - start + 1);
}

void ConfigReader::load_config_file(const String &file_name) {
	ifstream fs(file_name);

	if (!fs.is_open()) {
		throw runtime_error("Unable to open config file: " + file_name);
	}

	String line;
	while (getline(fs, line)) {
		line = _trim(line);

		// ignore empty lines, comments or sections
		bool invalid_line = line.empty() || line[0] == '#' || line[0] == ';' || line[0] == '[';

		if (invalid_line) {
			continue;
		}

		size_t pos = line.find('=');
		if (pos == String::npos) {
			continue;
		}

		String key = _trim(line.substr(0, pos));
		String value = _trim(line.substr(pos + 1));

		if (key == "port") {
			if (value.empty()) {
				throw std::runtime_error("No port name in config file detected.");
			}

			port_name = value;
		} else if (key == "baudrate") {
			try {
				#if defined(__unix__) || defined(__linux__) || defined(__APPLE__) || defined(_MAC)
				if (value.size() > 1 && value[0] == 'B') {
					// get rid of "B"
					value = value.substr(1);
				}
				#endif

				baud_rate = stoul(value);
			} catch (...) {
				throw std::runtime_error("Invalid baudrate in config file.");
			}
		}
	}

	if (port_name.empty() || baud_rate == 0) {
		throw std::runtime_error("Missing port name or baud rate in config file.");
	}
}

String ConfigReader::get_port_name() const {
	return port_name;
};

unsigned long ConfigReader::get_baud_rate() const {
	return baud_rate;
};