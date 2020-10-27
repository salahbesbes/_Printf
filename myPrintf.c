
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "holberton.h"

/**
* checkType - check the char after % in the copyFormat str
* @str: str
* @i: index if char
* @vaList: va_list
*
* Return: void
*/

char *checkType(int i, char *str, va_list vaList)
{
	unsigned int b10;
	int ch;
	int nb;
	char *arg;

	switch (str[i])
	{
		case 'c':
			{
				ch = va_arg(vaList, int);
				{
					str = concatCharAt(i - 1, str, ch);
					str = deleteChar(i, str);
				}
				break;
			}
		case 'i':
			{
				b10 = va_arg(vaList, int);
				arg = convertBase(b10, 10);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;
			}
		case 'd':
			{
				nb = va_arg(vaList, int);
				arg = numToString(nb);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;
			}
		case 's':
			{
				arg = va_arg(vaList, char*);
				if (arg == NULL)
				{
					str = concatAt(i - 1, str, "(null)");
				 
					str = deleteChar(i, str);
					break;
				}
				else
				{
					str = concatAt(i - 1, str, arg);
					str = deleteChar(i, str);
					break;
				}
				
			}
		case 'b':
			{
				b10 = va_arg(vaList, unsigned int);
				arg = convertBase(b10, 2);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;


			}
		case 'u':
			{
				b10 = va_arg(vaList, unsigned int);
				arg = convertBase(b10, 10);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;
			}
		case 'o':
			{
				b10 = va_arg(vaList, unsigned int);
				arg = convertBase(b10, 8);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;
			}
		case 'x':
			{
				b10 = va_arg(vaList, unsigned int);
				arg = convertBase(b10, 16);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;

			}
		case 'X':
			{
				b10 = va_arg(vaList, unsigned int);
				arg = convertBase(b10, 16);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;

			}
		case 'R':
			{
				arg = va_arg(vaList, char*);
				arg = rot13(arg);
				/*
				for (nb = 0; arg[i]; nb++)
				{
					printf(" arg[nb] = %c\n", arg[nb]);
				}
				*/
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;

			}
		case 'r':
			{
				arg = va_arg(vaList, char*);
				arg = rev_string(arg);
				str = concatAt(i - 1, str, arg);
				str = deleteChar(i, str);
				break;
			}




		default:
			break;
	}
	return (str);
}

/**
 * _printf - My printf
 * @format: const char
 *
 * Return: nb of char printed
 */

int _printf(const char *format, ...)
{
	unsigned int i = 0, ok = 0;
	va_list vaList;
	char *copyFormat, *str;

	copyFormat = strCopyAlloc(format);
	i = _strlen(copyFormat);
	va_start(vaList, format);
	i = 0;
	while (copyFormat[i])
	{
		if (copyFormat[i] == '%' )
		{
			
			ok = checkTypeForClean(copyFormat[i]);
			if (ok == 2)
			{
				copyFormat = handlePercent(i, copyFormat);
				i++;

			}
			if (ok == 0)
				copyFormat = handlePercent(i, copyFormat);
			copyFormat = checkType(i + 1, copyFormat, vaList);
			}
		i++;
	}
	for (i = 0; copyFormat[i]; i++)
	;
	_puts(copyFormat);
	free(copyFormat);
	va_end(vaList);
	return (i);
}
