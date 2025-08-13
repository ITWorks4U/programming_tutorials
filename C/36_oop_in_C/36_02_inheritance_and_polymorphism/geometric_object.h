/*
* In general, an inheritance allows you to define a base class with basic settings,
* whereas each derived class implements all public and protected members and
* methods.
*
* Well, in C this is also possible, but with limitations.
*/

#ifdef __cplusplus
extern "C" {
#endif

#ifndef GEOMETRIC_OBJECT_H
#define GEOMETRIC_OBJECT_H

//	usually, under Windows M_PI is unknown
#ifndef M_PI
#define M_PI  3.1415926535897932384626433
#endif


/// @brief Contains a general design pattern for any 2D geometric object.
typedef struct Shape Shape;

/// @brief A function table. Often called "virtual table". This is required to define
/// a "base abstract class".
typedef struct {
	double (*area)(const Shape *self);
	double (*perimeter)(const Shape *self);
	void (*print)(const Shape *self);
} ShapeVTable;

/// @brief The "base class" itself.
struct Shape {
	const ShapeVTable *vtable;
};

//	"interface functions" for shape
//	are not planned to use for the direct way, however, those
//	must refer to the vtable struct, otherwise your inheritance,
//	as well as, polymorphism won't work
static inline double shape_area(const Shape *s) {
	return s->vtable->area(s);
}

static inline double shape_perimeter(const Shape *s) {
	return s->vtable->perimeter(s);
}

static inline void shape_print(const Shape *s) {
	s->vtable->print(s);
}
#endif

#ifdef __cplusplus
}
#endif