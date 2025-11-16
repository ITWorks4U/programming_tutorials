#include <iostream>
#include "config_reader.h"
#include "serial_connection.h"

using namespace std;

int main() {
	ConfigReader cr;

	cout << "using connection settings: " <<
	"[port: " << cr.get_port_name() << ", baud: " << cr.get_baud_rate() << "]"
	<< endl;

	SerialConnection sc(cr);

	// valid_commands: "system_info", "led_green_on", "led_green_off", "led_yellow_on", "led_yellow_off", "led_red_on", "led_red_off"

	if (sc.on_existing_serial_ports()) {
		cout << "Enter h for help, q to quit." << endl;

		while (true) {
			cout << "command: ";
			String msg;
			getline(std::cin, msg);

			if (msg == "h") {
				// display help
				sc.print_all_commands();
				continue;
			}

			if (msg == "q") {
				break;
			}

			if (sc.on_valid_command(msg)) {
				sc.write(msg + "\n");
				cout << "Waiting for response..." << endl;

				String reply = (msg == "system_info") ? sc.read_full_response() : sc.read_line();
				cout << "Received: " << reply << endl;
			} else {
				cerr << "unknown command: \"" << msg << "\"" << endl;
			}
		}
	}

	return 0;
}