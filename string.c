#include "main.h"
/**
*_strlen - gives the length of a string
*@s: the string to check
*Return: the length of the string
*/
int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);
	while (*s++)
		i++;
	return (i);
}

/**
*_strcmp - compares 2 strings
*@s1: string 1
*@s2: string 2
*Return: the result
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
*starts_with - checks for needle and haystack
*@haystack: parameter
*@needle: parameter
*Return: address of the result
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
*_strcat - concantenates 2 strings
*@dest: destination
*@src: the source
*Return: pointer to dest
*/
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
