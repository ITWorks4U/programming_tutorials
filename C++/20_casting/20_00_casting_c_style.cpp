/*
* Casting a variable / object to another variable / object
* helps you to work quick and (mostly) without issues,
* however, this also causes logical errors followed by
* undefined behaviors.
*/

#include <iostream>

// for calloc, free (C)
#include <cstdlib>

//	handling with C-Strings
#include <cstring>

using namespace std;

#define BUFFER_LENGTH   30
#define LIGHT_YEAR      9.461e15

struct Person {
	int person_id;

	//	C-Strings with fixed known size
	//	holds up to 29 characters + '\0'
	char f_name[BUFFER_LENGTH];
	char l_name[BUFFER_LENGTH];

	//	dynamic C-String with unknown size
	//	usually 8 Bit for 64 Bit architecture,
	//	but that does not mean, that you can
	//	store only 7 characters...
	char *birth_date;
};

void casting_examples_0() {
	//	using C-style casting can be used in C++, but
	//	this has a bunch of pitfalls, e. g.:
	//	- you don't often see the brackets
	//	- datatype overflow / underflow
	//	- does hardly throw an error
	//	...

	cout << "light year: " << LIGHT_YEAR << endl;

	int ly_int = (int) LIGHT_YEAR;
	cout << "light year as int: " << ly_int << endl;

	//...
}

void casting_examples_1() {
	/*
	* allocating memory for a structure
	* In C programming a cast is optional, but in C++ it's strictly required!
	*
	* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	* In C++ this (or similar) build error appears:
	* 'A value of type "void *" cannot be used to initialize an entity of type "Person *"'
	* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	*
	* void *calloc(size_t _nmemb, size_t __size);
	*   returns a pointer to an allocated structure with n bytes
	*   depending on the size of the structure => in that case 72 bytes
	*
	* attention: A pointer has a different size of n bytes, depending on the machine you're working on.
	* 64 bit: 8 bytes
	* 32 bit: 4 bytes
	* 16 bit: 2 bytes
	* 8 bit: 1 byte
	*
	* If you want more to learn about pointers, then take a look to:
	* C-Programming / chapter 26 (memory management)
	*/

	//	typical C-style casting
	Person *p = (Person *) calloc(1, sizeof(Person));
	if (p == nullptr) {
		perror("calloc(Person)");
		return;
	}

	p->person_id = 1;
	strcpy(p->f_name, "Chuck");
	strcpy(p->l_name, "Norris");

	p->birth_date = (char *) calloc(BUFFER_LENGTH, sizeof(char));
	if (p->birth_date == nullptr) {
		perror("calloc(p->birth_date)");
		free(p);
		return;
	}

	strcpy(p->birth_date, "1940-03-10");

	cout <<
		"[" << p->person_id << ", " << p->f_name <<
		", " << p->l_name << ", " << p->birth_date <<
		"]"
	<< endl;

	/*	***		some operations here	***		*/
	//	since calloc() was in use to allocate memory,
	//	we must release the memory by our own
	free(p);
}

int main() {
	/*
	* fun fact:
	* On a Windows system this application might be detected by the antivirus application
	* as a "virus", because you're using very old and security flaw C instructions,
	* functions, ... for C++.
	*/

	//	using simple castings
	casting_examples_0();

	//	using dynamic allocation...
	casting_examples_1();

	return 0;
}