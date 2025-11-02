/* using arrays from given array class */

#include <iostream>
#include <array>
using namespace std;

int main() {
	// array class, where given type and amount of elements are defined here
	// in that case: integer array with 16 elements
	//
	// array<type, number_of_elements>
	//    - if less than the maximum number of elements exists, the numbers left will be
	//      filled with 0
	//    - if more than the maximum number of elements exists, then the application can't
	//      be built
	array<int32_t, 16> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	cout << "arr contains: " << arr.size() << " elements" << endl <<
	"Is this array empty? " << (arr.empty() ? "yes" : "no") << endl <<
	"What is the maximum size for that array? " << arr.max_size() << endl;

	// classic for:
	for(size_t i = 0; i < arr.size(); i++) {
		cout << arr[i] << endl;
	}

	// for-each:
	for(int32_t element : arr) {
		cout << element << endl;
	}

	return 0;
}