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
	tcp::acceptor acceptor(io_context);

	// open a new connection (IPv6 by default)
	acceptor.open(tcp::v6());

	// also allow IPv4 connections
	acceptor.set_option(asio::ip::v6_only(false));

	// bind and listen
	acceptor.bind(tcp::endpoint(tcp::v6(), c.get_port_number()));
	acceptor.listen();

	cout << "Server is listening on " << c.get_host_name() << "/" << c.get_port_number() << endl;

	while(true) {
		cout << "waiting for a client connection..." << endl;
		tcp::socket socket(io_context);

		// blocks until a client has been connected
		acceptor.accept(socket);
		cout << "Client connected: " << socket.remote_endpoint() << endl;

		while(true) {
			array<char, 1024> data{};
			error_code error;

			size_t length = socket.read_some(asio::buffer(data), error);

			if (error == asio::error::eof) {
				cout << "Connection closed by client." << endl;
				break;
			} else if (error) {
				throw system_error(error);
			}

			String received(data.data(), length);
			cout << "received: " << received << endl;

			String reply = "Echo: " + received;
			asio::write(socket, asio::buffer(reply), error);
		}
	}

	return 0;
}