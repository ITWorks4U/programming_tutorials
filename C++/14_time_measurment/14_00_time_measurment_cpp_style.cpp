#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void print_time(long long seconds) {
	cout << "duration: " << seconds / 3600 << "h, " << seconds / 60 << "min, " << seconds % 60 << "s" << endl;
}

int main() {
	//	unlike to write:
	//	std::chrono::steady_clock::time_point (Have fun to read this. >:-) )
	//	use auto keyword instead

	auto start = high_resolution_clock::now();
	cout << "Hit enter to see the measured time. " << endl << "waiting paitently..." << endl;

	//	runs endless until the enter key
	//	has been pressed
	while(true) {
		if (cin.get()) {
			break;
		}
	}

	cout << "Done!" << endl;
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<seconds>(end - start);
	print_time(duration.count());

	return 0;
}