#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"
#include <stddef.h>



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
* munToString - convert int ro string
* @n: int
*
* Return: str need free()
*/

char *numToString(int n)
{
	int i = 0, m = 0, nb = 0, len = 0;
	char *str;

	nb = n;
	if (nb < 0)
		nb *= -1;
	for (m = 0; nb > 0; nb /= 10, m++)
	;
	len = m - 1;
	if (n < 0)
	{
		nb = -n;
		str = malloc(sizeof(char) * (m + 1));
		str[0] = '-';
		for (i = m; i > 0; i--, nb /= 10)
			str[i] = (nb % 10) + '0';
		str[m + 1] = '\0';

	}
	else
	{
		str = malloc(sizeof(char) * (m));
		for (i = len; i >= 0; i--, n /= 10)
			str[i] = (n % 10) + '0';
		str[len + 1] = '\0';
	}
	return (str);
}

