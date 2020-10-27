#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"


/**
* handlePercent - if we found '%' we will replace replce it by '\'
* @a: 
*
* Return:
*/

char *handlePercent(int index, char *p)
{

	int i, len;
	char *newP;
/*
	for (len= 0; p[len]; len++)
	;
	newP = malloc(sizeof(char) * len);
	for (i = 0; i < len; i++)
	{
		if (i < index)
			newP[i] = p[i];
		if (i >= index)
			newP[i] = p[i + 1];
	}
	printf("len newP = %d\n", i);
*/	
	
	for (i = index; p[i]; i++)
		p[i] = p[i + 1];

	return (p);
}
