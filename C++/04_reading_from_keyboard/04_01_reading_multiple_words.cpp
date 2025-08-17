#include <iostream>
#include <string>
using namespace std;

int main() {
	string content;
	cout << "enter something: ";

	//	read everything until the enter key ('\n') has been detected
	//	allows to read multiple words (similar to fgets())
	getline(cin, content);

	cout << "content contains: " << content << endl;

	return 0;
}