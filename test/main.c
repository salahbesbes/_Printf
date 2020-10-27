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
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;
    

    int a=10; 
int* p =&a; 
_printf("%x\n", &a); 
    /*
    size_t Gb = 1024*1024*1024;
char *a = (char *)malloc(2 * Gb * sizeof(char));
char *b = (char *)malloc(2 * Gb * sizeof(char));
printf("use %%X: a=%X\n", a);
printf("use %%X: b=%X\n", b);
printf("use %%p: a=%p\n", a);
printf("use %%p: b=%p\n", b); 
    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;

	_printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);

    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    printf("\v\n");
	printf(" Negative:[-762534] \nNegative:[-762534]\nUnsigned:[2147484671]\nUnsigned:[2147484671]\nUnsigned octal:[20000001777]\nUnsigned octal:[20000001777]\nUnsigned hexadecimal:[800003ff, 800003FF]\nUnsigned hexadecimal:[800003ff, 800003FF] \n");
     * */
	/*
	_printf("\"  \\ \\n \n", NULL,"holberton", '\t');
	printf("\"  \\ \\n \n", NULL, "holberton", '\t');

	_printf("%s %c%%sa\n", "salah", '*');
	printf("%s %c%%sa\n", "salah", '*');
_printf("%%");
printf(" epxpect = %\n");
_printf("%");
printf(" epxpect = (nothing printed)\n");
_printf("%%r");
printf(" epxpect = %r\n");
_printf("hello%%");
printf(" epxpect = hello%\n");
_printf("minehello%");
printf(" epxpect = minehello\n");
_printf("hello%r");
printf(" epxpect = hello%r\n");
_printf("mineUnknown:[%r]\n");
_printf("mineCharacter:[%c]\n", 'H');
_printf("Let's try to printf a simple sentence.\n");
_printf("String:[%s]\n", "I am a string !");
_printf("String:[%s]\n", "I am a string !");
	   _printf("hello%%\n");
	   _printf("%%\n");
	   _printf("%%r\n");
mineCharacter:[H]
mineCharacter:[H]
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
String:[I am a string!]
String:[I am a string!]
 * */
return (0);

}


