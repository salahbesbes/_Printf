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
* convertBase - convert a positice integer to any base
* @num: unsigned int to convert
* @base: (2 - 8 - 10 - 16)
* Return: str need free()
*/

char *convertBase(unsigned int num, int base)
{
	char bases[] = "0123456789ABCDEF";

	char *ptr, *buffer;
	int i;

	buffer = malloc(sizeof(char) * 50);
	/* filling the array from the end to the start*/
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		/* *--ptr   is executed before the assainment do*/
		*--ptr = bases[num % base]; /* base[48] = 'reste' */
		num /= base; /* our counter */
	} while (num != 0);

	/* we are not traiting the negative int*/



	return (ptr);
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
* _atoi - transform a str of numbers to a numeric integer
* @s: string
*
* Return: int
*/

int _atoi(char *s)
{

	int j, firstNumber = 1, negatif = 1;
	unsigned int num = 0;

	j = 0;
	while (s[j] && firstNumber)
	{
		if (s[j] == '-' && !num)
			negatif *= -1;
		if (s[j] >= '0' && s[j] <= '9' && firstNumber)
		{
			num *= 10;
			num += s[j] - '0';
		}
		else if (num > 0)
			firstNumber = 0;
		j++;
	};
	num *= negatif;
	return (num);
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
/**
* concatAt - concat *src to *des at position pos
* @pos: position from where we cant to concat
*
* Return: str need free()
*/

char *concatAt(int pos, const char *des, char *src)
{

	int i, j, k;
	int len1 = 0, len2 = 0, newStrLength = 0;
	char *newStr;

	if (!src)
		src = "";
	if (!des)
		des = "";
	for (len1 = 0; des[len1]; len1++)
	;
	for (len2= 0; src[len2]; len2++)
	;
	newStrLength = len1 + len2;
	if (*src == '\0')
		return ((char *)des);
	if (pos > len1)
		return ("cant concat");

	newStr = malloc(sizeof(char) * (newStrLength + 1));
	for (i = 0 , j = 0, k = 0; i < newStrLength ; i++)
	{
		if (src[k] && i > pos)
		{
			newStr[i] = src[k];
			k++;
		}
		else
		{
			newStr[i] = des[j];
			j++;
		}
	}
	newStr[i] = '\0';
	return (newStr);
}

/**
* checkTypeForClean - we check char after % if there is a special char representing
* the type if we found we return 1
* @c: char
*
* Return: 1
* Error: 0
*/

int checkTypeForClean(char c)
{
	char type[] = "sdifxulc";
	int i;

	for (i = 0; type[i]; i++)
	{
		if (c == type[i])
			return (1);
	}
	return (0);
}

/**
* deleteChar - we search for how many char we have between % and the type (f,
* d, x ...)  then we replace them with other char (those after the type) in the
* ned we end up with  a string without (%0.5f) and arguments
* @pos: index of the %
* @p: is an  allocated array of char (copy of format)
* Description: we check on every char after % untill we found the first one,
* when we do we save nb of char in between (nb).
*
* Return: the length of the char we want to delete including % and type
*/

int deleteChar(int pos, char *p)
{

	int i,j, nb, ok, len;

	for (i = pos; p[i]; i++)
	{
		if (p[i] == '%')
		{
			for (j = 0;p[i + j] ; j++)
			{
				ok = checkTypeForClean(p[i + j]);
				if (ok)
				{
					nb = j + 1;
					break;
				}
			}
			break;
		}
	}
	for (i = pos; i < (pos + nb); i++)
		p[i] = p[ i + nb];
	return (nb);
}
/**
* cleanTypeArg - delete any char between all % and type (f, d , x ...) in a
* string 
* @format: const str
*
* Description: in all cases we will end up with an array length is equal less then
* the original, we allocate a char array and we pass it into other functions so
* that we can work on it 
* Return: str need free()
*/

char *cleanTypeArg(const char *format)
{

	int len = 0, nb, i;
	char *p;

	for (len = 0; format[len]; len++)
	;
	p = malloc(sizeof(char) * (len + 1));

	for (i = 0; format[i]; i++)
		p[i] = format[i];
	p[i] = '\0';
	for (i = 0; p[i]; i++)
	{
		if (p[i] == '%')
			nb = deleteChar(i, p);
	}
	return (p);
}

/**
* concatCharAt - concat a char to a string at pos 
* @pos: concat at pos
* @str: string
* @c: char
*
* Return: str
*/

char *concatCharAt(int pos, const char *str, char c)
{
	int i, j, k;
	int len1 = 0, len2 = 0, newStrLength = 0;
	char *newStr;

	for (len1 = 0; str[len1]; len1++)
	;
	if (pos > len1 + 1)
		return ("cant concat");
	if (c == '\0' || !str)
		return (NULL);
	newStr = malloc(sizeof(char) * (len1 + 1));

	for (i = 0, j = 0; i < len1 + 1 ; i++)
	{
		if (i < pos)
			newStr[i] = str[i];
		if (i == pos)
			newStr[i] = c;
		if (i > pos)
		{
			newStr[len1 - j] = str[len1 - 1 - j];
			j++;
		}
	}
	newStr[i] = '\0';
	return (newStr);

}
/**
* main - create my own printf
* @argc: nb of arguments
* @argv: arguments
*
* Return: 0
* Error: 1
*/
int main(int argc, char *argv[])
{

	unsigned int res, i;
	char *p, *ptr;

	_putchar('\n');
	_printf("4 %s ", "this is string " );
	_printf("5 %s %c %c", "string", '*', '4');
	/*
	_putchar('\n');
	_printf("6 %d ", 210);
	_putchar('\n');
	_printf("7%i", 053);
	_putchar('\n');
	_printf("8 \n");
	_printf("9\n");
	*/
	
	return (0);
}

