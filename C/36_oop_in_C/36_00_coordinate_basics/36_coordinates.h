/*
* Basicly you can't do OOP in C, however, with some tricks this
* can be simulated including limitations.
*
* You can use structures, function pointers and
* some limited design patterns.
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef COORDINATES_H
#define COORDINATES_H

// a mark for an "invalid value", e. g. using NULL pointer
// instead of a valid object instance
#define INVALID_VALUE	0xFFFF

/*
* forward declaration;
*
* Usually in your header or source file this structure is
* defined and declared. The header has just the definition,
* so it shall be impossible to create an instance directly.
*
* fun fact: there's no need to use a forward declaration
* in your header file, but this is also a way to do this
*/

/// @brief Contains the coordinates {x;y}.
struct Coordinate;

//	function prototypes

/// @brief Create and return a new coordinate instance. This simulates a constructor.
/// @param x X coordinate
/// @param y Y coordinate
/// @return the new created instance or NULL on failure
struct Coordinate *coord_create(const int x, const int y);	

/// @brief Remove the coordinate from memory. This simulates a destructor.
/// @param self 
void coord_destroy(struct Coordinate *self);

/// @brief Receive the current X coordinate.
/// @param self the known coordinate instance
/// @return position X
int coord_get_x(const struct Coordinate *self);

/// @brief Receive the current Y coordinate.
/// @param self the known coordinate instance
/// @return position Y
int coord_get_y(const struct Coordinate *self);

/// @brief Add two {x;y} coordinates.
/// If c1 or c2 is NULL, the coordinate {0,0} returns instead.
/// @param c1 first coordinate
/// @param c2 second coordinate
///	@return new Coordinate point
struct Coordinate *coord_add(const struct Coordinate *c1, const struct Coordinate *c2);

/// @brief Subtract two {x;y} coordinates.
/// If c1 or c2 is NULL, the coordinate {0,0} returns instead.
/// @param c1 first coordinate
/// @param c2 second coordinate
/// @return new Coordinate point or {0;0} if c1 or c2 is NULL
struct Coordinate *coord_subtract(const struct Coordinate *c1, const struct Coordinate *c2);

/// @brief Do a dot product of two coordinates. Both coordinates must exist.
/// If c1 or c2 is NULL, UNDEF_VALUE returns instead.
/// @param c1 first coordinate
/// @param c2 second coordinate
/// @return Dot product of c1•c2 or UNDEF_VALUE if c1 or c2 is NULL
int dot_product(const struct Coordinate *c1, const struct Coordinate *c2);

/// @brief Do a cross product of two coordinates. Both coordinates must exist.
/// If c1 or c2 is NULL, UNDEF_VALUE returns instead.
/// @param c1 first coordinate
/// @param c2 second coordinate
/// @return Cross product of c1xc2 or UNDEF_VALUE if c1 or c2 is NULL
int cross_product(const struct Coordinate *c1, const struct Coordinate *c2);

#endif

#ifdef __cplusplus
}
#endif