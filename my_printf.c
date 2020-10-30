#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...)
{
	va_list valist;
	int i, *index, nbOfCharAdded = 0;
	int (*funcOfEachType)(va_list valist, int *index);
	int (*printLong)(va_list valist, int *index, char ch);
	int (*printShort)(va_list valist, int *index, char ch);
	
	index = &i;
	va_start(valist, format);
	if (format == NULL)
		return (0);
	i = 0;
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			/*
			   char *allFlags;
			allFlags = getAllFlags(i, (char *)format);
			checkflags(allFlags);
			printf(" allFlags = %s\n", allFlags);
			i++;
			treatAllCases(format, index, &nbOfCharAdded, valist);
			*/
			if (format[i + 1] == '%')
			{
				_putchar(format[i + 1]);
				i += 2;
				nbOfCharAdded--;
				continue;;
			}
			if (format[i + 1] == '\0')
			{
				i++;
				continue;
			}
			if (format[i + 1] == 'l')
			{
				printLong = checkLflags(format[i + 2]);
				if (printLong)
				{
					nbOfCharAdded += printLong(valist, index, format[i + 2]);
					i++;
				}
				else 
					i++;
				continue;
			}
			if (format[i + 1] == 'h')
			{
				printShort = checkShortFlags(format[i + 2]);
				if (printShort)
				{
					nbOfCharAdded += printShort(valist, index, format[i + 2]);
					i++;
				}
				else 
					i++;
				continue;

			}
			else
			{
			funcOfEachType = checkType(format[i + 1]);
			if (funcOfEachType)
				nbOfCharAdded += funcOfEachType(valist, index);
			else 
				i++;
			continue;
			}
		}
		_putchar(format[i]);
		i++;
	}
	va_end(valist);
	return (i + nbOfCharAdded);
}
