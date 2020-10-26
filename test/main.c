#include "../holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
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
   int len;
    int len2;
    unsigned int ui;
    void *addr;
    len = _printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
	_printf("[%d %d %i %i]", -598410, -15, -155 , -33);
	/* next is to trat negative numbers*/
    return (0);

}



