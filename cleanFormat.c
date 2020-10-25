#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <stddef.h>


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

char * deleteChar(int pos, char *p)
{

	int i,j, nb, ok, len;
	char *newP;

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
	for (j = i; j <= (i + nb) && p[j]; j++)
	{
		p[j] = p[j + nb];
		/*
		printf(" p[j+nb] = %c p[j] = %c \n", p[j + nb], p[j]);
		*/
		}
	
	
	return (p);
}

/**
* cleanTypeArg - delete any char between all % and type (f, d , x ...) in a
* string 
* @format: const str
*
* Description: in all cases we will end up wiath an array length is equal less then
* the original, we allocate a char array and we pass it into other functions so
* that we can work on it 
* Return: str need free()
*/
/*
char *cleanTypeArg(char *format)
{

	int len = 0, nb, i , j;
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
		{
			nb = deleteChar(i, p);
			for (j = i; j <= (i + nb); j++)
				p[j] = p[j + nb];
			p[j] = '\0';
		}
}
	return (p);
}
*/
