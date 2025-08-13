/*
* Implementation of all functionalities for the libary itself.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library_maker.h"

//	only available in this source file
static Element storage[MAX_NUMBER_OF_ELEMENTS] = {0};

void print_all_elements(void) {
	int nbr_of_elements = 0;

	for (size_t i = 0; i < MAX_NUMBER_OF_ELEMENTS; i++) {
		//	get rid of any element, which is "unknown" at this moment
		//	since this array holds up to 50 elements, not every array position
		//	contains a valid ID => those ID's are not count
		if (storage[i].element_id != 0) {
			nbr_of_elements++;

			//	even those three functions returns a char pointer
			//	these are not dynamically created C strings
			//	=> refers on the stack and will be vanished,
			//	when the scope has been left
			char *element_type = get_element_type(storage[i]._type);
			char *element_classification = get_classification(storage[i]._class);
			char *element_notification = get_notification(storage[i]._note);

			printf(
				" element: %s\n ID: %d\n symbol: %s\n melting point: %lf °C\n boiling point: %lf °C\n atomic mass: %lf\n type: %s\n class: %s\n notification: %s\n\n",
				storage[i].element_name, storage[i].element_id, storage[i].element_symbol, storage[i].melting_point,
				storage[i].boiling_point, storage[i].atomic_mass, element_type, element_classification, element_notification
			);
		}
	}

	printf("total number of elements: %d\n", nbr_of_elements);
}

void add_elements(void) {
	char *element_names[] = {"Gold", "Aluminium", "Radon", "Hydrogen", "Oxygen", "Nitride", "Brome"};
	char *element_symbols[] = {"Au", "Al", "Rd", "H", "O", "N", "Br"};
	double melting_points[] = {1064.18, 660.2, -71.0, -259.14, -218.3, -210.1, -7.3};
	double boiling_points[] = {2970.00, 2470.00, -61.8, -252, -183.0, -196.0, 58.5};
	double atomic_masses[] = {196.966570, 26.9815384, 222, 1.008, 15.999, 14.0067, 79.904};
	ElementType types[] = {SOLID, SOLID, SOLID, GAS, GAS, GAS, LIQUID};
	Classification classes[] = {NOBLE_METAL, METAL, NOBLE_GAS, NON_METAL, NON_METAL, NON_METAL, NON_METAL};
	Notification notifications[] = {NATURAL, NATURAL, RADIOACTIVE, NATURAL, NATURAL, NATURAL, NATURAL};

	for(int i = 0; i < 7; i++) {
		Element e;
		e.element_id = i+1;
		strcpy(e.element_name, element_names[i]);
		strcpy(e.element_symbol, element_symbols[i]);
		e.melting_point = melting_points[i];
		e.boiling_point = boiling_points[i];
		e.atomic_mass = atomic_masses[i];
		e._type = types[i];
		e._class = classes[i];
		e._note = notifications[i];

		storage[i] = e;
	}
}

bool on_noble_element(Element e) {
	return e._class == NOBLE_METAL || e._class == NOBLE_GAS;
}

char *get_element_type(ElementType e) {
	switch(e) {
		case SOLID:
			return _SOLID;
		case LIQUID:
			return _LIQUID;
		case GAS:
			return _GAS;
	}

	return NULL;
}

char *get_classification(Classification c) {
	switch(c) {
		case METAL:
			return _METAL;
		case SEMI_METAL:
			return _SEMI_METAL;
		case NON_METAL:
			return _NON_METAL;
		case NOBLE_METAL:
			return _NOBLE_M;
		case NOBLE_GAS:
			return _NOBLE_G;
	}

	return NULL;
}

char *get_notification(Notification n) {
	switch(n) {
		case NATURAL:
			return _NATURAL;
		case ARTIFICIALLY:
			return _ART;
		case RADIOACTIVE:
			return _RADIO;
	}

	return NULL;
}