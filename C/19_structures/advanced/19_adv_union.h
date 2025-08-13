#ifndef ADV_UNION_H
#define ADV_UNION_H

//	normal way
union Coordinates_3 {
	int x;
	int y;
};

//	also possible:
//	point_2 automatically refers to Coordinates_4
union Coordinates_4 {
	int x;
	int y;
}point_2;

//	using an anonymous union
//	this must contain at least one member, otherwise
//	this anonymous union can't be used
//
//	In C a warning on compile time may appear here, but C++
//	also refuses to build your application.
#ifndef __cplusplus
union {
	int x;
	int y;
};
#endif

//	that's might also be an anonymous union,
//	but this can be refered by an object instace instead
union {
	int x;
	int y;
}point_3;

//	"modern" union
typedef union {
	int x;
	int y;
}Coordinates_5;

#endif