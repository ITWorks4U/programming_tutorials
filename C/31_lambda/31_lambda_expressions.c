/*
* Usually, C doesn't comes with any lambda expression to speed up instructions,
* however, by using macro instructions, this can be simulated.
*
* hint: On an IDE / OS it may happen, that the lambda expression might be wrong.
* This can be ignored, unless, this function really does have an error elsewhere.
*/

#ifdef __cplusplus
#error "This custom lamdba expression works on C only. Use the built in lambda functions for C++ instead."
#else

#warning "This application may cause an undefined behavior!"

#include <stdio.h>
#include <stdlib.h>

/*
* customized lambda function to let calculate the average value of numbers
*
* attention:
* since macros are typeless, you can use the lambda function for anything
* to receive the average values including an undefined behavior >:-)
*
* lambda$_ret => return type
* lambda$_args => arguments to work with
* lambda$_body => what that lambda function shall do
*/
#define LAMBDA(lambda$_ret, lambda$_args, lambda$_body) ({\
	lambda$_ret lambda$__anon$ lambda$_args lambda$_body &lambda$__anon$;\
})

static double collection[] = {3.141, 2.713, 9e3, 3e-5};
static int int_collection[] = {1,2,3,4,5,6,7,8,9,10};
static char word[] = "You can also use lambda expressions in C! These are rather difficult to C++.";

//	-----------
//	a general function
//	for any type
//	-----------
double average_apply(double (*fn)(double)) {
	double avg = 0.0;
	int nbrOfElements = sizeof(collection)/sizeof(collection[0]);

	for (int i=0; i < nbrOfElements; i++) {
		avg += fn(collection[i]);
	}

	return avg/nbrOfElements;
}

//	-----------
//	some special functions
//	-----------
int summary_apply(int (*fn)(int inp)) {
	int sum = 0;
	int nbrOfElements = sizeof(int_collection)/sizeof(int_collection[0]);

	for(int i = 0; i < nbrOfElements; i++) {
		sum += fn(int_collection[i]);
	}

	return sum;
}

char word_apply(char (*fn)(char inp)) {
	char sign = '\0';
	int nbrOfElements = sizeof(word)/sizeof(word[0]);

	for(int i = 0; i < nbrOfElements; i++) {
		sign += fn(word[i]);
	}

	return sign;
}

//	-----------
//	main
//	-----------
int main(void) {
	printf("average (double) = %lf\n",average_apply(LAMBDA(double, (double x), {return x;})));
	printf("average (int) = %lf\n",average_apply(LAMBDA(double, (double x), {return x*x;})));
	printf("average (C-String) = %lf\n",average_apply(LAMBDA(double, (double x), {return x/3;})));

	printf("sum (int)= %d\n", summary_apply(LAMBDA(int, (int x), {return x;})));

	char ret = word_apply(LAMBDA(char, (char x), {return x;}));
	printf("sum (C-String): sign = %c (%d)\n", ret, (int) ret);

	return EXIT_SUCCESS;
}
#endif