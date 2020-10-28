#include <stdio.h>
#include <stdlib.h>
#include "holberton.h"


/**
* handlePercent - if we found '%' we will replace replce it by '\'
* @index: int
* @p: str
*
* Return:newP
*/

char *handlePercent(int index, char *p)
{

	int i;

	for (i = index; p[i]; i++)
		p[i] = p[i + 1];

	return (p);
}
