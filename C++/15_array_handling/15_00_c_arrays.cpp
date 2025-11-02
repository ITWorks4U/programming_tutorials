/*
* Handling arrays like in C. Usually, you can do this,
* but if you want to use some additional features, like
* determine the number of elements in an array, shown here,
* or how often a number exists in that array, use one of
* the other examples instead.
*/

#include <iostream>
using namespace std;

int main() {
	// It's possible to use C-arrays.
	int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

	// Determine array elements? No!
	size_t nbr_of_elements = sizeof(array);
	cout << "wrong way: array contains " << nbr_of_elements << " elements" << endl;

	// correct way to determine array elements
	nbr_of_elements = sizeof(array) / sizeof(array[0]);
	cout << "correct way: array contains " << nbr_of_elements << " elements" << endl;

	/*
	* The first attempt gives you the amount of bytes of the given array
	* depending on the amount of elements and their data type,
	* therefore nbr_of_elements gives you 64 "array elements",
	* 16 elements * 4 byte for each element,
	* whereas 16 expected elements shall be there.
	*/

	cout << "get all array elements by C-style: " << endl << "[ ";

	for(size_t i = 0; i < nbr_of_elements; i++) {
		cout << array[i] << " ";
	}
	cout << "]" << endl << "--------------" << endl <<
	"get all array elements by C++-style: " << endl << "[ ";

	// "lazy way": iterates automatically trough the whole array (16 times)
	for(int a : array) {
		cout << a << " ";
	}
	cout << "]" << endl;

	return 0;
}