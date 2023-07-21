#include "main.h"
/**
*_memset - fills memory with const byte
*@s: pointer
*@b: byte
*@n: no of bytes
*Return: a pointer to memory
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int v;

	for (v = 0; v < n; v++)
	{
		s[v] = b;
	}
	return (s);
}

/**
*ffree - frees a string of strs
*@pp: str of strs
*/
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
*_realloc - reallocates memory
*@ptr: pointer
*@old_size: old block
*@new_size: new block
*Return: pointer to old block
*/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *a;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);
	a = malloc(new_size);
	if (!a)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		a[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (a);
}
