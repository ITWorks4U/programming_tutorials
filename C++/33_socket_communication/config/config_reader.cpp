/*
* Read the config file and offers a class pattern to work with.
*/

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

		// ignore empty lines or comments
		bool invalid_line = line.empty() || line[0] == '#' || line[0] == ';';

		if (invalid_line) {
			continue;
		}

		size_t pos = line.find('=');
		if (pos == String::npos) {
			continue;
		}

		String key = _trim(line.substr(0, pos));
		String val = _trim(line.substr(pos + 1));

		if (key == "host") {
			host_name = val;
		} else if (key == "port") {
			try {
				port_number = std::stoi(val);
			} catch (...) {
				throw runtime_error("Invalid port number in config file.");
			}
		}
	}

	if (host_name.empty() || port_number < 1) {
		throw std::runtime_error("Missing host or port in config file.");
	}
}

String ConfigReader::get_host_name() const {
	return this->host_name;
}

int ConfigReader::get_port_number() const {
	return this->port_number;
}