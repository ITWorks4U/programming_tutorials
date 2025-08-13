/*
* define structure(s), function(s), datatype(s), constant(s), ...
* whatever you want, which shall be converted into a library
*
* attention:
* - usually a ".dll" file exists on Windows only
*   - those can also be used on a linux enviroment, however, those are hardly used or useful
* - on a linux enviroment a *.so" file is in use there
* - on a macOS enviroment a *.dylib" file is use instead
*
* - in Visual Studio, however, a library is not easy to create or implement
*/

#ifndef LIBRARY_MAKER_H
#define LIBRARY_MAKER_H

//	this is optional, but often used for Windows;
//	because the library must be able to load on runtime
#ifdef _WIN32
	#ifdef LIBARY_MAKER_EXPORTS
		#define LIBARY_MAKER_API __declspec(dllexport)
	#else
		#define LIBARY_MAKER_API __declspec(dllimport)
	#endif
#else
	#define LIBARY_MAKER_API
#endif

/*	simple implementation for a periodic system	*/

//	--------------
//	libary
//	--------------
#include <stdbool.h>

//	--------------
//	constants
//	--------------

#define ELEMENT_LENGTH	101
#define SYMBOL_LENGTH	4
#define MAX_NUMBER_OF_ELEMENTS	50
#define _SOLID		"SOLID"
#define _LIQUID		"LIQUID"
#define _GAS		"GAS"
#define _METAL		"METAL"
#define _SEMI_METAL	"SEMI METAL"
#define _NON_METAL	"NO METAL"
#define _NOBLE_M	"NOBLE METAL"
#define _NOBLE_G	"NOBLE GAS"
#define _NATURAL	"NATURAL"
#define _ART		"ARTIFICIALLY"
#define	_RADIO		"RADIOACTIVE"

//	--------------
//	structures
//	--------------

/// @brief contains an element type in the range of {solid, liquid, gas}
typedef enum {
	SOLID = 0, LIQUID = 1, GAS = 2
} ElementType;

/// @brief contains the element classification in the range of {metal, semi metal, no metal, noble metal, noble gas}
typedef enum {
	METAL = 0, SEMI_METAL = 1, NON_METAL = 2, NOBLE_METAL = 3, NOBLE_GAS = 4
} Classification;

/// @brief Contains the element notification in the range of {naturally existing, artificially existing, radioactive}.
/// Usually, an element can be natually and also radioactive as well as artificially and radioactive, but this is
/// not in use here.
typedef enum {
	NATURAL = 0, ARTIFICIALLY = 1, RADIOACTIVE = 2
} Notification;

/// @brief Contains an element image.
typedef struct {
	int element_id;
	char element_name[ELEMENT_LENGTH];
	char element_symbol[SYMBOL_LENGTH];
	double melting_point;
	double boiling_point;
	double atomic_mass;

	ElementType _type;
	Classification _class;
	Notification _note;
} Element;

//	--------------
//	function prototypes
//	--------------

/// @brief Print all elements from the array to stdout.
LIBARY_MAKER_API void print_all_elements(void);

/// @brief Check, if the given element is a noble element.
/// This is a noble element only, if the classification is set to
/// NOBLE_GAS or NOBLE_METAL
/// @param e the element to check
/// @return true, if e is a noble element, otherwise false
LIBARY_MAKER_API bool on_noble_element(Element e);

/// @brief Add some elements to use.
LIBARY_MAKER_API void add_elements(void);

/// @brief Returning the element type as a word.
/// @param e certain element type
/// @return the element type as a word of NULL, if not found
LIBARY_MAKER_API char *get_element_type(ElementType e);

/// @brief Returning the element classification as a word.
/// @param c certain classification type
/// @return the element classification as a word or NULL, if not found
LIBARY_MAKER_API char *get_classification(Classification c);

/// @brief Returning the element notification as a word.
/// @param n certain notification type
/// @return the element notification as a word or NULL, if not found
LIBARY_MAKER_API char *get_notification(Notification n);

//	any other functions here...
#endif