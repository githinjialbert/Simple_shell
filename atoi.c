#include "main.h"
/**
*interactive - runs if shell is ok
*@info: parameter
*Return: 1 if correct 0 if not
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
*is_delim - checks for a delimeter
*@c: character to check
*@delim: delimeter
*Return: 1 if correct 0 if not
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
*_isalpha - chcks for an alphabet
*@v: the char to check
*Return: 1 if correct 0 if not
*/
int _isalpha(int v)
{
	if ((v >= 'a' || v <= 'z') && (v >= 'A' || v <= 'Z'))
		return (1);
	else
		return (0);
}

/**
*_atoi - converts a string to an int
*@a: string to convert
*Return: 0 if correct 1 if not
*/
int _atoi(char *a)
{
	int v, sign = 1, flag = 0, output;
	unsigned int final = 0;

	for (v = 0; a[v] != '\0' && flag != 2; v++)
	{
		if (a[v] == '-')
			sign *= -1;
		if (a[v] >= '0' && a[v] <= '9')
		{
			flag = 1;
			final *= 10;
			final += (a[v] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		output = -final;
	else
		output = final;
	return (output);
}
