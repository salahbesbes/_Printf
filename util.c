#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"

/**
* reallocCopy - realloc and copy
* @format: str
* @newSize: int
*
* Return: str
*/

char *reallocCopy(char *format, int newSize)
{
	int i, len;
	char *newP;

	for (len = 0; format[len]; len++)
	;

	newP = malloc(sizeof(char) * (newSize + 1));

	for (i = 0; i < newSize + 1; i++)
	{
		if (format[i])
			newP[i] = format[i];
		else
			newP[i] = '*';
	}
	newP[i] = '\0';
	return (newP);
}

/**
* strCopyAlloc - copy and allocate str
* @format: const str
*
* Return: new pointer
*/

char *strCopyAlloc(const char *format)
{
	int i, len;
	char *p;

	for (len = 0; format[len]; len++)
	;

	p = malloc(sizeof(char) * (len + 1));

	for (i = 0; format[i]; i++)
		p[i] = format[i];
	p[i] = '\0';

	return (p);
}
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

int _strlen(const char *str)
{
	unsigned int i;

	for (i = 0; str[i]; i++)
	;
	return (i);
}


