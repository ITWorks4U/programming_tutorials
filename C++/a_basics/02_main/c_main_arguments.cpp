#include <iostream>
using namespace std;

// handle any amount of arguments, which is required for your purpose
// argc := argument counter
// argv := argument vector (contains all arguments, which can be accessed by argc)
//
// NOTE: every argument is a word, even there's a number or else
// NOTE: argv can also be written as char *argv[]
int main(int argc, char **argv) {
	cout << "number of arguments:" << argc << endl;

	// even you're not using any arguments, the first argv and argc is set to one element:
	// your application name (with absolute path) itself
	for(int i = 0; i < argc; i++) {
		cout << "argument " << i << ": " << argv[i] << endl;
	}

	return 0;
}