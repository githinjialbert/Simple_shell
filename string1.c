#include "main.h"
/**
*_strcpy - copies a string
*@dest: destination
*@src: source
*Return: a ptr to the dest
*/
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
*_strdup - duplicates a string
*@str: string to duplicate
*Return: a pointer to str
*/
char *_strdup(const char *str)
{
	int length = 0;
	char *ret;

	if (str == NULL)
	{
		return (NULL);
	}
	while (*str++)
		length++;
	ret = malloc(sizeof(char) * (length + 1));
	if (!ret)
		return (NULL);
	for (length++; length--;)
		ret[length] = *--str;
	return (ret);
}

/**
*_puts - prints an input str
*@str: the str to print
*Return: void
*/
void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
		_putchar(str[w]);
	i++;
}

/**
*_putchar - writes the char to output
*@c: char to print
*Return: 1 if correct 0 if otherwise
*/
int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
