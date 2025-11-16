#include <iostream>
#include <sstream>
#include <algorithm>
#include <thread>
#include <filesystem>
#include "serial_connection.h"

using namespace std;
using StringBuilder = std::stringstream;

SerialConnection::SerialConnection(const ConfigReader &cfg_reader) : io_(), serial_(io_) {
	Vector detected_ports = scan_ports();

	if (detected_ports.capacity() > 0) {
		cout << "found " << detected_ports.capacity() << " port(s): ";

		for (String port : detected_ports) {
			cout << port << ", ";
		}

		cout << endl;

		try {
			serial_.open(cfg_reader.get_port_name());
			serial_.set_option(asio::serial_port_base::baud_rate(cfg_reader.get_baud_rate()));
			serial_.set_option(asio::serial_port_base::character_size(8));
			serial_.set_option(asio::serial_port_base::stop_bits(asio::serial_port_base::stop_bits::one));
			serial_.set_option(asio::serial_port_base::parity(asio::serial_port_base::parity::none));
			serial_.set_option(asio::serial_port_base::flow_control(asio::serial_port_base::flow_control::none));

			ports_existing = true;
		} catch (exception &e) {
			cerr << "serial error: " << e.what() << endl;
		}
	} else {
		cerr << "Error: No serial communication port(s) detected." << endl;
	}
}

SerialConnection::~SerialConnection() {
	if (serial_.is_open()) {
		serial_.close();
	}
}

void SerialConnection::write(const String& msg) {
	asio::write(serial_, asio::buffer(msg));
}

String SerialConnection::read_line() {
	asio::streambuf buffer;
	asio::read_until(serial_, buffer, '\n');
	istream is(&buffer);
	String line;

	getline(is, line);
	return line;
}

String SerialConnection::read_full_response() {
	StringBuilder sb;
	char c = ' ';
	asio::error_code ec;

	// NOTE: In this used standalone asio version 1.36.0 the
	//       read_some function blocks the serial communication channel,
	//       when no more character has been transmitted. This leads
	//       to an infinite application run. To avoid this, a special
	//       received character marks the end of the communication data.
	//
	// NOTE: This current version does not comes with methods, like
	//       serial_non_blocking(true); or lowest_layer().non_blocking(true, ec);
	//       or else or are unavailable.
	while(serial_.read_some(asio::buffer(&c, 1), ec) > 0) {
		// cout << "=> c:" << c << " <=> " << static_cast<int>(c) << endl;

		if (ec) {
			break;
		}

		sb << c;

		// NOTE: Depending on the formatted message on the microcontroller
		//       this is the last character, which has been transmitted by
		//       the serial communication. If this character has been received
		//       the message has been fully transmitted.
		//
		// NOTE: Depending on the microcontroller it may also happen, that other
		//       sub messages, which also ends with ')' may assume, that the full
		//       message has been transmitted. In that case an another special
		//       termination character or word or else shall be used instead.
		if (c == ')') {
			break;
		}
	}

	return sb.str();
}

Vector SerialConnection::scan_ports() {
	Vector ports;

	#ifdef _WIN32
	// Windows: COMx [x = 1,2,...,256]
	for (int i = 1; i <= 256; ++i) {
		String port_name = "COM" + to_string(i);

		HANDLE h = CreateFileA(
			port_name.c_str(), GENERIC_READ | GENERIC_WRITE,
			0, nullptr, OPEN_EXISTING, 0, nullptr
		);

		if (h != INVALID_HANDLE_VALUE) {
			ports.push_back(port_name);
			CloseHandle(h);
		}
	}
	#endif

	#if defined(__unix__) || defined(__linux__)
	// Linux: typical device patterns
	const Vector patterns = {"/dev/ttyUSB", "/dev/ttyACM", "/dev/ttyS"};

	for (const auto& prefix : patterns) {
		for (int i = 0; i < 64; ++i) {
			String dev = prefix + to_string(i);
			if (filesystem::exists(dev)) {
				ports.push_back(dev);
			}
		}
	}
	#endif

	#if defined(__APPLE__) || defined(_MAC)
	// macOS: devices are under /dev with prefixes
	// NOTE: never tested
	for (const auto& entry : filesystem::directory_iterator("/dev")) {
		auto path = entry.path().String();
		if (path.find("/dev/cu.") == 0 || path.find("/dev/tty.") == 0) {
			ports.push_back(path);
		}
	}
	#endif

	return ports;
}

bool SerialConnection::on_existing_serial_ports() const {
	return this->ports_existing;
}

bool SerialConnection::on_valid_command(const String input) {
	return any_of(valid_commands.begin(), valid_commands.end(), [&](const auto& cmd) {
		return input == cmd;
	});
}

void SerialConnection::print_all_commands() {
	StringBuilder sb;
	sb << "{";

	for (string cmd : valid_commands) {
		sb << cmd << ", ";
	}

	// get rid of space character and last comma
	sb.seekp(-2, sb.cur);
	sb << "}";

	cout << "commands to use: " << sb.str() << endl;
}