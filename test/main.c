#include "../holberton.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#define UNUSED(x) (void)(x)
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
	printf(" 20 = %d\n", 20);
   

_printf("---\t-----\n");

	int k =  _printf("%s%c%s%c%s%c\n", "ahmed",' ',"besbes", '-', "Salah",'*');
	_printf(" k = %d\n", k);

	/*
_printf("%%\n");
_printf("%");
_printf("%%r\n");
_printf("hello%%\n");
_printf("minehello%");
_printf("hello%r\n");
_printf("mineUnknown:[%r]\n");
_printf("mineCharacter:[%c]\n", 'H');
_printf("Let's try to printf a simple sentence.\n");
_printf("String:[%s]\n", "I am a string !");
_printf("mineCharacter:[%c]\n", 'H');
_printf("String:[%s]\n", "I am a string !");
	   _printf("hello%%\n");
	   _printf("%%\n");
	   _printf("%%r\n");
%
(nothing/error)
%r
hello%
minehello
hello%r
mineUnknown:[%r]
mineCharacter:[H]
mineCharacter:[H]
Let's try to printf a simple sentence.
Let's try to printf a simple sentence.
String:[I am a string!]
String:[I am a string!]
 * */
return (0);

}


