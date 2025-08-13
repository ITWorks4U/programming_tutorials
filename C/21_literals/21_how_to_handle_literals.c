/*
* Literals allows you to specify a value for a certain data type,
* which might be useful for a correct handling.
*
* Literals are often in use for numbers in macro definitions.
*
* |  literal    |  effect                 |
* |-------------|-------------------------|
* |  U          |  unsigned integer       |
* |  L          |  long                   |
* |  LU or UL   |  unsinged long          |
* |  LL         |  long long              |
* |  LLU or ULL |  unsigned long long     |
* |  0B         |  binary expression      |
* |  0          |  octal expression       |
* |  0x         |  hexadecimal expression |
* |  F          |  floating point         |
* |  ' '        |  character literal      |
* |  " "        |  string literal         |
*/

//	by default, it might be interpreted as signed integer
#define EXPRESSION_0	1000

//	unsigned integer
#define EXPRESSION_1	1000U

//	long integer
#define EXPRESSION_2	1000L

//	long long integer (1000i64)
#define EXPRESSION_3	1000LL

//	binary expression => 1000 => 8 in decimal
#define EXPRESSION_4	0B1000

//	octal expression => 512 in decimal
#define EXPRESSION_5	01000

//	hexadecimal expression => 4096 in decimal
#define EXPRESSION_6	0x1000

//	floating point expression only
#define EXPRESSION_7	1000.0F

//	double expression only
#define EXPRESSION_8	1000.0

//	character literal only => 70 in decimal
#define EXPRESSION_9	'F'

//	string literal only, even this contains a single character only
//	Guess what? C-String comes with \0 => "F" has a length of 2 bytes.
#define EXPRESSION_10	"F"

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	for(int i = 0; i < 11; i++) {
		printf("EXPRESSION_%d: ", i);

		switch(i) {
			case 0:
				printf("%d\n", EXPRESSION_0);
				break;
			case 1:
				printf("%u\n", EXPRESSION_1);
				break;
			case 2:
				printf("%ld\n", EXPRESSION_2);
				break;
			case 3:
				#ifdef _WIN32
				//	Windows can't handle (unsigned) long long int correctly
				printf("%I64d\n", EXPRESSION_3);
				#else
				printf("%lld\n", EXPRESSION_3);
				#endif
				break;
			case 4:
				printf("%d\n", EXPRESSION_4);
				break;
			case 5:
				printf("%d\n", EXPRESSION_5);
				break;
			case 6:
				printf("%d\n", EXPRESSION_6);
				break;
			case 7:
				printf("%f\n", EXPRESSION_7);
				break;
			case 8:
				printf("%lf\n", EXPRESSION_8);
				break;
			case 9:
				printf("%c\n", EXPRESSION_9);
				break;
			case 10:
				printf("%s\n", EXPRESSION_10);
				break;
			default:
				continue;
		}
	}

	//	also a commonly pitfall: Is there a float or a double value?
	//	-------------------
	//	It may happen, that you'll see the output: "Yeah, this is the same."
	//	at the first attempt, however, this is not a 100% guarantee on each
	//	runtime or system.
	//
	//	By default, "1.0" is set to a double value. Since float and double are
	//	not the same, it may happen, that "1.0" is unequal to "1.0".
	//
	//	To make sure to use a float value instead, add a floating point literal
	//	behind the number (F)
	float upper_limit = 1.0;

	if (1.0F == upper_limit) {
		puts("Yeah, this is the same.");
	} else {
		puts("Wait a minute...");
	}

	return EXIT_SUCCESS;
}