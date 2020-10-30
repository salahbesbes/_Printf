#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdarg.h>
#include <stdio.h>
typedef struct m
{
	char t;
	int (*f)(va_list valist, int *index) ;
} print_t;

typedef struct constFormat
{
	char flags;
	int (*handleFlags)(va_list valist, int *index);
} constFormat;
int (*checkflags(char *str))(va_list valist, int *i);
char *getAllFlags(int pos, char *p);

char *strCopyAlloc(char *format);
int _printf(const char *format, ...);
int _puts(char *str);
int _putchar(char c);
int checkFlagsForType(char c);
int print_c(va_list arg, int *index);
int print_dec(va_list arg, int *index);
int print_int(va_list arg, int *index);
int rev_string(va_list vaList, int *index);
int print_strings(va_list arg, int *index);
int numToString(va_list vaList, int *index);
int toBase2(va_list vaList, int *index);
int toBase8(va_list vaList, int *index);
int toBase16(va_list vaList, int *index);
int toBase16X(va_list vaList, int *index);
int toBase10(va_list vaList, int *index);
int replaceNonPrintableChar(va_list vaList, int *index);
int checkNonPrintableChar(char ch);
int convertLongIntToBase16(long int num);
int handleP(va_list vaList, int *index);
int rot13(va_list vaList, int *index);
int handleL(va_list vaList, int *index);
int treatAllCases(const char *format, int *i, int *nbOfCharAdded, va_list valist);
int (*checkType(char ch))(va_list valist, int *i);





#endif
