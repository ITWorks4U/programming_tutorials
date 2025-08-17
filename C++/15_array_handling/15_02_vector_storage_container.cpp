/*
* using arrays from given vector class
*
* allows you to use	an iterator, if you like
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
	//	vector class, where given type is defined here
	//	in that case: integer array with 16 elements
	//	unlike to array<type, nbr_of_elements> you just need
	//	vector<type> to hold any amount of elements
	vector<int32_t> vector_array = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	//	similar to <array>:
	cout << "vector_array contains: " << vector_array.size() << " elements" << endl <<
	"Is this vector empty? " << (vector_array.empty() ? "Yes." : "No.") << endl <<
	"Capacitiy of that vector: " << vector_array.capacity() << endl;

	//	for:
	for(size_t i = 0; i < vector_array.size(); i++) {
		cout << vector_array[i] << endl;
	}

	//	for-each:
	for(int32_t element : vector_array) {
		cout << element << endl;
	}

	//	using an iterator:
	//	define an own iterator
	typedef vector<int32_t>::iterator it;
	for(it i = vector_array.begin(); i != vector_array.end(); i++) {
		cout << *i << endl;

		//	a pointer is required here to receive the value, where
		//	that pointer points on the given memory address
	}

	return 0;
}