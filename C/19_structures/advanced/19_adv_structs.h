#ifndef ADV_STRUCTS_H
#define ADV_STRUCTS_H

// normal way
struct Coordinates_0 {
	int x;
	int y;
};

// also possible:
// in that case point_0 can automatically be used for Coordinates_1
struct Coordinates_1 {
	int x;
	int y;
}point_0;

// using an anonymous struct
// this must contain at least one member, otherwise
// this anonymous struct can't be used
//
// In C a warning on compile time may appear, but C++ refuses to build your
// application.
#ifndef __cplusplus
struct {
	int x;
	int y;
};
#endif

// that's might also be an anonymous struct,
// but this can be refered by an object instace instead
struct {
	int x;
	int y;
}point_1;

// "modern" struct
typedef struct {
	int x;
	int y;
}Coordinates_2;

// -------------
// this does not declare functions to a structure, but you can
// enumate those by using a pointer => pointers are handled later
//
// the fuctions to use here are in the source file instead
//
// can also be used for unions, but those are a rarely used 
typedef struct{
	int (*add)(int, int);
	int (*substact)(int, int);
	// ...
} Calculation;
// -------------

#endif