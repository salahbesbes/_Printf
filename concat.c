#include "holberton.h"
#include <stddef.h>
#include <stdlib.h>

/**
* concatCharAt - concat a char to a string at pos 
* @pos: concat at pos
* @str: string
* @c: char
*
* Return: str
*/

char *concatCharAt(int pos, const char *str, char c)
{
	int i, j, k;
	int len1 = 0, len2 = 0, newStrLength = 0;
	char *newStr;

	for (len1 = 0; str[len1]; len1++)
	;
	if (pos > len1 + 1)
		return ("cant concat");
	if (c == '\0' || !str)
		return (NULL);
	newStr = malloc(sizeof(char) * (len1 + 1));

	for (i = 0, j = 0; i < len1 + 1 ; i++)
	{
		if (i < pos)
			newStr[i] = str[i];
		if (i == pos)
			newStr[i] = c;
		if (i > pos)
		{
			newStr[len1 - j] = str[len1 - 1 - j];
			j++;
		}
	}
	newStr[i] = '\0';
	return (newStr);

}
/**
* concatAt - concat *src to *des at position pos
* @pos: position from where we cant to concat
*
* Return: str need free()
*/

char *concatAt(int pos, const char *des, char *src)
{

	int i, j, k;
	int len1 = 0, len2 = 0, newStrLength = 0;
	char *newStr;

	if (!src)
		src = "";
	if (!des)
		des = "";
	for (len1 = 0; des[len1]; len1++)
	;
	for (len2= 0; src[len2]; len2++)
	;
	newStrLength = len1 + len2;
	if (*src == '\0')
		return ((char *)des);
	if (pos > len1)
		return ("cant concat");

	newStr = malloc(sizeof(char) * (newStrLength + 1));
	for (i = 0 , j = 0, k = 0; i < newStrLength ; i++)
	{
		if (src[k] && i > pos)
		{
			newStr[i] = src[k];
			k++;
		}
		else
		{
			newStr[i] = des[j];
			j++;
		}
	}
	newStr[i] = '\0';
	return (newStr);
}
