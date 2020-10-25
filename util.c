#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
/**
* _puts - print a string
* @str: str
*
* Return: void
*/

void _puts(char *str)
{
	unsigned int i;

	if (!str)
	{
		_putchar('N');
		_putchar('U');
		_putchar('L');
		_putchar('L');
		exit(98);
	}
	/*
	if (*str == '\0')
	{
		_putchar('\'');
		_putchar('\'');
		exit(98);
	}
	*/
	for (i = 0; str[i]; i++)
	{
		_putchar(str[i]);
	}
	_putchar('\n');

}


/**
* _putchar - print single char
* @c: char
*
* Return: int
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}


/**
* _strlen - return the length of the string
* @str: str
*
* Return: length except '\0'
*/

int _strlen(char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	;
	return (i);
}


