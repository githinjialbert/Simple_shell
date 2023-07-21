#include "main.h"
/**
*_erratoi - converts a string to an int
*@a: the string to be renewed
*Return: 0 if successful -1 if otherwise
*/
int _erratoi(char *a)
{
	int v = 0;
	unsigned long int final = 0;

	if (*a == '+')
		a++;
	for (v = 0; a[v] != '\0'; v++)
	{
		if (a[v] >= '0' && a[v] <= '9')
		{
			final *= 10;
			final += (a[v] - '0');
			if (final > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (final);
}

/**
*print_error - prints error msg
*@info: message parameter
*@estr: contains spec msg
*Return: 0 if successful -1 if not
*/
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
*print_d - prints a decimal
*@input: parameter
*@fd: file descriptor
*Return: no of chars
*/
int print_d(int input, int fd)
{
	int (*_putchar)(char) = _putchar;
	int v, hesabu = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		_putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = input;
		_putchar('-');
		hesabu++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (v = 1000000000; v > 1; v /= 10)
	{
		if (_abs_ / v)
		{
			_putchar('0' + current / v);
			hesabu++;
		}
		current %= v;
	}
	_putchar('0' + current);
	hesabu++;

	return (hesabu);
}

/**
*convert_number - a clone of itoa
*@num: a no
*@base: a base
*@flags: arg flags
*Return: str
*/
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';
	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do {
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);
	if (sign)
		*--ptr = sign;
	return (ptr);
}

/**
*remove_comments - it removes the comments #
*@buf: & of str to modify
*Return: 0
*/
void remove_comments(char *buf)
{
	int v;

	for (v = 0; buf[v] != '\0'; v++)
	{
		if (buf[v] == '#' && (!v || buf[v - 1] == ' '))
		{
			buf[v] = '\0';
			break;
		}
	}
}
