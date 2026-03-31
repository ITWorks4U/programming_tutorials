#include <iostream>
#include <asio.hpp>
#include "config_reader.h"

// NOTE: The certain asio.hpp header file must either be included into
//       this project or a linked reference (-I<path>) is required,
//       where the header file is located to let compile the application.

using asio::ip::tcp;
using namespace std;
using String = std::string;

int main() {
	ConfigReader c;

	asio::io_context io_context;

	tcp::resolver resolver(io_context);
	auto endpoints = resolver.resolve(c.get_host_name(), to_string(c.get_port_number()));

	tcp::socket socket(io_context);
	asio::connect(socket, endpoints);

	cout << "connected to " << c.get_host_name() << ":" << c.get_port_number() << endl;

	while(true) {
		cout << "Enter message (or 'quit'): ";
		String message;
		getline(cin, message);

		if (message == "quit") {
			break;
		}

		asio::write(socket, asio::buffer(message));

		array<char, 1024> reply{};
		error_code error;
		size_t length = socket.read_some(asio::buffer(reply), error);

		if (error == asio::error::eof) {
			cout << "Server closed connection.\n";
			break;
		} else if (error) {
			throw system_error(error);
		}

		cout << "Server replied: " << String(reply.data(), length) << endl;
	}

	return 0;
}
