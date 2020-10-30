#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>


/*
*/
int (*checkLflags(char ch))(va_list valist, int *index, char ch)
{
	int j, i, found = -1;

	constFormat m[] = {
		{'u', printLongUnsigned},
		{'d', printLongUnsigned},
		{'i', printLongUnsigned},
		{'x', printLongUnsigned},
		{'X', printLongUnsigned},
		{'o', printLongUnsigned},
		{'\0', NULL}
	};

	for (j = 0; m[j].flags; j++)
	{

		if (ch == m[j].flags)
			return (m[j].handleFlags);
	}
	return (NULL);
		
}
