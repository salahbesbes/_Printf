#include <stdio.h>
#include <stdarg.h>
#include "../holberton.h"

/**
* checkType - check the char after % in the format str
* @format: str
* @int: index if char
* Return: void
*/

void checkType(int i, const char *format, va_list vaList)
{
	unsigned int j;
	int ch;
	int nb;
	char *str;


	switch (format[i])
	{
		case 'c':
			{
				ch = va_arg(vaList, int);
				{
					str = concatCharAt(i - 2, format, ch);
					str = cleanTypeArg(str);
					_puts(str);
				}
				break;
			}
		case 'i':
			{
				nb = va_arg(vaList, int);
				str = p_int(nb);
				str = concatAt(i - 2, format, str);
				str = cleanTypeArg(str);
				_puts(str);
				break;
			}
		case 'd':
			{
				nb = va_arg(vaList, int);
				str = p_dec(nb);
				str = concatAt(i - 2, format, str);
				str = cleanTypeArg(str);
				_puts(str);
			     
				break;
			}
		case 's':
			{
				str = va_arg(vaList, char*);
				if (str)
				{
					str = concatAt(i - 2, format, str);
					str = cleanTypeArg(str);
					_puts(str);
				}
				else
					printf("(nil)");
				break;
			}
		default:
			break;

	}
	
}


int _printf(const char *format, ...)
{
	unsigned int i = 0;
	va_list vaList;
	

	va_start(vaList, format);
	while (format[i])
	{
		if (format[i] == '%')
			checkType(i + 1, format, vaList);

		i++;
	}
	va_end(vaList);
	return (0);
}
