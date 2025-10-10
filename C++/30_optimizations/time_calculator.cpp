#include "time_calculator.h"

void print_time(long long seconds) {
	long long hours = seconds / 3600;
	long long minutes = seconds / 60;
	long long remaining_seconds = seconds % 60;
	long long milli_seconds = seconds * 1000;
	long long micro_seconds = seconds * 1000000;
	long long nano_seconds = seconds * 1000000000;

	std::cout << "duration: " <<
		hours << "h, " << minutes << "min, " << remaining_seconds << "s, " <<
		milli_seconds << "ms, " << micro_seconds << "(micro)s, " << nano_seconds << "ns"
	<< std::endl;
}