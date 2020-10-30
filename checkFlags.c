#include <stdarg.h>
#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>
int (*checkflags(char *str))(va_list valist, int *index)
{
		int j, found = 0, i, k;
		char *flags;

		print_t m[] = {
			{'u', print_dec},
			{'d', print_c},
			{'\0', NULL}
		};
			
		for (i = 0; str[i]; i++)
		{
			for (j = 0; m[j].t; j++)
			{
				if (str[i] == m[j].t)
					printf(" j = %d\n", j);
			}
		}

	return (NULL);
		
}
