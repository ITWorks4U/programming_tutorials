/*
	Monitoring your system with a refresh time of 100ms.

	(C) 2024 ITWorks4U
*/

#include "../header/gtk_full_tutorial.h"

int cpu_util = 0;
int cpu[DOUBLE_BUFF] = {0};
GdkRGBA color;