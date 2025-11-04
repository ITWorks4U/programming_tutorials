#ifndef EXTERN_H
#define	EXTERN_H

/*
* The keyword extern allows us to define a variable,
* function, expression, ... which can be
* declared elsewhere. Very often for variables, which
* are defined in the header file and implemented in at
* least two source files, the compiler complains about
* a multiple definition of a variable.
*
* To avoid this, the variable is defined with extern
* keyword in the header file.
*
* Make sure, that this value is available on building
* process, otherwise you'll receive an undefined reference.
*
* By the way, it makes no sense to declare a function with
* extern, because a function can almost always be called
* from outside. Except, this function is declared with static.
*
* The same nonsense effect with extern is with struct, enum, union.
*
* hint: don't mark a function with static in a header file
* or in the source file, because this causes a compiler error
*
* An external struct, union can be used, however, this is rarly used as well.
* This makes sense only to hide the declaration of that structure from outside,
* where in the source file this struct / union can have different content
*/

// "just" a definition here
extern int data;

// normal struct
struct test_0 {
	int a;
	int b;
};

// external defined structure, which
// must be declared in a source file
//
// the compiler may print a warning about
// "useless storage class specifier in empty declaration"
extern struct test_1;

#endif