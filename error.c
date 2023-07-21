#include "main.h"
/**
*_eputs - prints and input str
*@str: the string to be printed
*Return: 0
*/
void _eputs(char *str)
{
	int v = 0;

	if (!str)
		return;
	while (str[v] != '\0')
	{
		_eputchar(str[v]);
		v++;
	}
}

/**
*_eputchar - writes a char to stderr
*@a: the char to write
*Return: 1 if successful and -1 if otherwise
*/
int _eputchar(char a)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(2, buf, v);
		v = 0;
	}
	if (a != BUF_FLUSH)
		buf[v++] = a;
	return (1);
}

/**
*_putfd - writes the char to a given file
*@a: the char to write
*@fd: the file descriptor
*Return: 1 if successful -1 if otherwise
*/
int _putfd(char a, int fd)
{
	static int v;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || v >= WRITE_BUF_SIZE)
	{
		write(fd, buf, v);
		v = 0;
	}
	if (a != BUF_FLUSH)
		buf[v++] = a;
	return (1);
}

/**
*_putsfd - prints a string
*@str: the string to print
*@fd: the file descriptor
*Return: 0
*/
int _putsfd(char *str, int fd)
{
	int v = 0;

	if (!str)
		return (0);
	while (str)
	{
		v += _putfd(*str++, fd);
	}
	return (v);
}
