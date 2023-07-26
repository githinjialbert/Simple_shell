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
	int i, j = 0;
	char *s = dest;

	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			dest[j] = '\0';
			j++;
		}
	}
	return (s);
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
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
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
