/*
* Since an union and a struct may have different purposes,
* those can also be combined. Also known as "tagged unions".
*
* Those can be used to hold one of several types, but we need
* to know which one currently stored.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH_BUFFER 50
#define LENGTH_ZIP 6

typedef struct {
	union {
		struct {
			char city[LENGTH_BUFFER];
			char zip[LENGTH_ZIP];
			char first_name[LENGTH_BUFFER];
			char last_name[LENGTH_BUFFER];
		} priv;

		struct {
			char city[LENGTH_BUFFER];
			char zip[LENGTH_ZIP];
			char first_name[LENGTH_BUFFER];
			char last_name[LENGTH_BUFFER];
		} pub;
	};
} Address; 

int main() {
	size_t size_of_address = sizeof(Address);
	printf("Amount of bytes for Address: ");

	#if _WIN32
	printf("%u\n", size_of_address);
	#else
	printf("%lu\n", size_of_address);
	#endif

	//	attentions:
	//	without an array an accessing to a member also affects the other members
	//	since C-strings are in use they contains garbage on runtime => are not fixed here by using memset()
	//	if you try to build that sample in C++ make sure NOT to use C++ keywords, like "public", "private", ...

	Address a[2];

	strcpy(a[0].pub.city, "New York");
	strcpy(a[0].pub.zip, "10001");
	strcpy(a[0].pub.first_name, "Adam");
	strcpy(a[0].pub.last_name, "Johnsons");

	strcpy(a[1].pub.city, "Miami");
	strcpy(a[1].pub.zip, "33101");
	strcpy(a[1].pub.first_name, "Adam");
	strcpy(a[1].pub.last_name, "Johnsons");

	printf("private address: %s, %s, %s, %s\n", a[0].priv.city, a[0].priv.zip, a[0].priv.first_name, a[0].priv.last_name);
	printf("public address: %s, %s, %s, %s\n", a[1].pub.city, a[1].pub.zip, a[1].pub.first_name, a[1].pub.last_name);

	return EXIT_SUCCESS;
}