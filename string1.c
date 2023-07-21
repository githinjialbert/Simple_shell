#include "main.h"
/**
*_strcpy - copies a string
*@dest: destination
*@src: source
*Return: a ptr to the dest
*/
char *_strcpy(char *dest, char *src)
{
	int v = 0;

	if (dest == src || src == 0)
		return (0);
	while (src[v])
	{
		dest[v] = src[v];
		v++;
	}
	dest[v] = 0;
	return (dest);
}

/**
*_strdup - duplicates a string
*@str: string to duplicate
*Return: a pointer to str
*/
char *_strdup(const char *str)
{
	int len = 0;
	char *ter;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
		len++;
	ter = malloc(sizeof(char) * (len + 1));
	if (!ter)
		return (NULL);
	for (len++; len--;)
		ter[len] = *--str;
	return (ter);
}

/**
*_puts - prints an input str
*@str: the str to print
*Return: void
*/
void _puts(char *str)
{
	int w = 0;

	if (!str)
		return;
	while (str[w] != '\0')
		_putchar(str[w]);
	w++;
}

/**
*_putchar - writes the char to output
*@c: char to print
*Return: 1 if correct 0 if otherwise
*/
int _putchar(char c)
{
	static int w;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || w >= WRITE_BUF_SIZE)
	{
		write(1, buf, w);
		w = 0;
	}
	if (c != BUF_FLUSH)
		buf[w++] = c;
	return (1);
}
