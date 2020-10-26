#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

/**
* concatCharAt - concat a char to a string at pos
* @pos: concat at pos
* @format: string
* @c: char
*
* Return: newstr
*/

char *concatCharAt(int pos, char *format, char c)
{
	int i, j;
	int len1 = 0;
	char *newStr;

	for (len1 = 0; format[len1]; len1++)
	;
	if (pos > len1 + 1)
		return ("cant concat");
	if (c == '\0' || !format)
		return (NULL);
	newStr = malloc(sizeof(char) * (len1 + 2));

	for (i = 0; i < (len1 + 2) ; i++, j++)
	{
		if (i < pos)
			newStr[i] = format[i];
		if (i == pos)
			newStr[i] = c;
		if (i > pos)
			newStr[i] = format[i - 1];
	}


	newStr[i] = '\0';
	free(format);
	return (newStr);

}
/**
* concatAt - concat *src to *format at position pos
* @pos: position from where we cant to concat
* @format: str
* @src: substring to be copied
* Return: str need free()
*/

char *concatAt(int pos, char *format, char *src)
{

	int i, j, k;
	int len1 = 0, len2 = 0, newStrLength = 0;
	char *newStr;

	if (!src)
		src = "";
	if (!format)
		format = "";
	for (len1 = 0; format[len1]; len1++)
	;
	for (len2 = 0; src[len2]; len2++)
	;
	newStrLength = len1 + len2 + 1;

	if (*src == '\0')
		return (format);
	if (pos > len1)
		return ("cant concat");


	newStr = malloc(sizeof(char) * newStrLength);
	for (i = 0, j = 0, k = 0; i < newStrLength; i++)
	{
		if (src[k] && i >= pos)
		{
			newStr[i] = src[k];
			k++;
		}
		else
		{
			newStr[i] = format[j];
			j++;
		}
	}
	newStr[i] = '\0';
	free(format);
	return (newStr);
}
