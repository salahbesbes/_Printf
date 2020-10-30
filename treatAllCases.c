#include <stdarg.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <stddef.h>


/**
* treatAllCases - treat all case after the % char
* @a: 
*
* Return: nb of char
*/

int treatAllCases(const char *format, int *i, int *nOfChar, va_list valist)
{
	
	int (*funcOfEachType)(va_list valist, int *index);

	if (format[*i + 1] == '%')
		{
			_putchar(format[*i + 1]);
			*i += 2;
		}
		if (format[*i + 1] == '\0')
		{
			*i += 1;
		}
		funcOfEachType = checkType(format[*i + 1]);
		if (funcOfEachType)
			*nOfChar += funcOfEachType(valist, i);
	else 
		*i += 1;
	
	return (*nOfChar);
}
