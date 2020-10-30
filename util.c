#include "holberton.h"
#include <stdarg.h>
#include <stdlib.h>
int print_c(va_list arg, int *index)
{
	char ch;
	ch = va_arg(arg, int);

	if (ch == 0)
	{
		printf(" salah besbes \n");
	}
	*index += 2;
	_putchar(ch);
  	return (1 - 2);    
}


	
/**
* _puts - print a string
* @str: str
*
* Return: void
*/

int _puts(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}

	return (i);
}
int print_strings(va_list arg, int *index)
{
	char *str;
	unsigned int i;

	*index +=2;
	str = va_arg(arg, char *);
	if (!str)
	{
		_puts("(null)");
		return ( 6 - 2);
	}
	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
	return (i - 2);
}
