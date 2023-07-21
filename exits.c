#include "main.h"
/**
**_strncpy - copies an str
*@dest: the destination
*@src: the source
*@n: the no of chars to be copied
*Return: the copied str
*/
char *_strncpy(char *dest, char *src, int n)
{
	int v, w;
	char *x = dest;

	while (src[v] != '\0' && v < n - 1)
	{
		dest[v] = src[v];
		v++;
	}
	if (v < n)
	{
		w = v;
		while (w < n)
		{
			dest[w] = '\0';
			w++;
		}
	}
	return (x);
}
/**
**_strncat - adds a string to another one
*@dest: the destination
*@src: the source
*@n: the no of chars to be conc
*Return: the conc str
*/
char *_strncat(char *dest, char *src, int n)
{
	int v, w = 0;
	char *u = dest;

	while (dest[w] != '\0')
		w++;
	while (src[v] != '\0' && v < n)
	{
		dest[w] = src[v];
		w++;
		v++;
	}
	if (v < n)
		dest[w] = '\0';
	return (u);
}
/**
**_strchr - locates a char
*@s: the string
*@c: the char to be searched for
*Return: a pointer
*/
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');
	return (NULL);
}
