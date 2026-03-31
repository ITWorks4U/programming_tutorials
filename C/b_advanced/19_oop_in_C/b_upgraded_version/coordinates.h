/*
* Unlike to the basic stuff, the functions can also
* be encapsuled inside the structure itself.
*
* By encapsulating the functions into the structure itself,
* it makes a better overview like a class in C++, Java, C#, Python, ...
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef COORDINATES_H
#define COORDINATES_H

// a mark for an "invalid value", e. g. using NULL pointer
// instead of a valid object instance
#define INVALID_VALUE	0xFFFF

/// @brief Contains the coordinates {x;y} including C-style "methods".
typedef struct Coordinate Coordinate;

struct Coordinate {
	int x;
	int y;

	// "methods"
	// usually, get_x and get_y are not required, because
	// you can also access to x and y on the direct way
	//
	// in C++ you could declare x, y into a private block

	/// @brief Receive the current X coordinate.
	/// @param self the known coordinate instance
	/// @return position X
	int (*get_x)(const Coordinate *self);

	/// @brief Receive the current Y coordinate.
	/// @param self the known coordinate instance
	/// @return position Y
	int (*get_y)(const Coordinate *self);

	/// @brief Add two {x;y} coordinates.
	/// If c1 or c2 is NULL, the coordinate {0,0} returns instead.
	/// @param c1 first coordinate
	/// @param c2 second coordinate
	/// @return new Coordinate point
	Coordinate *(*add)(const Coordinate *self, const Coordinate *other);

	/// @brief Subtract two {x;y} coordinates.
	/// If c1 or c2 is NULL, the coordinate {0,0} returns instead.
	/// @param c1 first coordinate
	/// @param c2 second coordinate
	/// @return new Coordinate point or {0;0} if c1 or c2 is NULL
	Coordinate *(*subtract)(const Coordinate *self, const Coordinate *other);

	/// @brief Do a dot product of two coordinates. Both coordinates must exist.
	/// If c1 or c2 is NULL, UNDEF_VALUE returns instead.
	/// @param c1 first coordinate
	/// @param c2 second coordinate
	/// @return Dot product of c1•c2 or UNDEF_VALUE if c1 or c2 is NULL
	int (*dot_product)(const Coordinate *self, const Coordinate *other);

	/// @brief Do a cross product of two coordinates. Both coordinates must exist.
	/// If c1 or c2 is NULL, UNDEF_VALUE returns instead.
	/// @param c1 first coordinate
	/// @param c2 second coordinate
	/// @return Cross product of c1xc2 or UNDEF_VALUE if c1 or c2 is NULL
	int (*cross_product)(const Coordinate *self, const Coordinate *other);
};

// function prototypes

/// @brief Create and return a new coordinate instance. This simulates a constructor.
/// @param x X coordinate
/// @param y Y coordinate
/// @return the new created instance or NULL on failure
struct Coordinate *coord_create(const int x, const int y);	

/// @brief Remove the coordinate from memory. This simulates a destructor.
/// @param self 
void coord_destroy(struct Coordinate *self);
#endif

#ifdef __cplusplus
}
#endif