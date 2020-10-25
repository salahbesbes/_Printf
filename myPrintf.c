
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
* checkType - check the char after % in the copyFormat str
* @copyFormat: str
* @int: index if char
* Return: void
*/
char *checkType(int i, char *str, va_list vaList)
{
	unsigned int j;
	int ch;
	unsigned int nb;
	char *arg;

	switch (str[i])
	{
		case 'c':
			{
				ch = va_arg(vaList, int);
				{
					str = concatCharAt(i - 1, str, ch);
				}
				break;
			}
		case 'i':
			{
				nb = va_arg(vaList, int);
				break;
			}
		case 'd':
			{
				nb = va_arg(vaList, int);
				break;
			}
		case 's':
			{
				arg = va_arg(vaList, char*);
				if (str)
				{
					str = concatAt(i - 1, str, arg);
					break;
				}
				printf("(nil)");
				break;
			}
		default:
			break;

	}

	return (str);
}


int _printf(const char *format, ...)
{
	unsigned int i = 0;
	va_list vaList;
	char *copyFormat;
	copyFormat = strCopyAlloc(format);
	va_start(vaList, format);
	i = 0;
	while (copyFormat[i])
	{
		if (copyFormat[i] == '%')
		{

			copyFormat = checkType(i + 1, copyFormat, vaList);
			copyFormat = deleteChar(i, copyFormat);
			i = 0;
			continue;
		}
		i++;
	}
	for (i = 0; copyFormat[i]; i++)
	;
	printf("%s\n", copyFormat);
	free(copyFormat);
	va_end(vaList);
	return (i);
}
