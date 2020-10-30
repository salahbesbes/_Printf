#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <stddef.h>


/**
* checkTypeForClean - we check char after % if there is a special char
* representing the type if we found we return 1
* @c: char
*
* Return: 1
* Error: 0
*/

int checkFlagsForType(char c)
{
	char type[] = "sifxulcdbegouxXRrp";
	int i;

	if (c == '\0')
		return (0);
	if (c == '%')
		return (2);

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

char *getAllFlags(int pos, char *p)
{

	int i, j, nb, ok, len;
	char *newP;

	for (len = 0; p[len]; len++)
	;
	ok = 0;
	for (i = pos; p[i]; i++)
	{
		if (p[i] == '%')
		{
			for (j = 0; p[i + j]; j++)
			{
				ok = checkFlagsForType(p[i + j]);
				if (ok == 1)
				{
					nb = j + 1;
					break;
				}
			}
			break;
		}
	}

	if (nb == 0)
		return (NULL);
	newP = malloc(sizeof(char) * (nb + 1));

	for (j = 0; j < (nb + 1); j++)
	{
		newP[j] = p[pos + j + 1];
	}
	newP[j] = '\0';
	return (newP);
}

