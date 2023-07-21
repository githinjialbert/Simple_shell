#include "main.h"
/**
*interactive - the shell in interaction
*@info: parameter
*Return: 1 if successful 0 if otherwise
*/
int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
*is_delim - looks for a delimeter
*@c: character
*@delim: the string delimeter
*Return: 1 if successful 0 if unsuccessful
*/
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
*_isalpha - checks for an alphabet
*@v: the char to check
*Return: 1 if correct 0 if incorrect
*/
int _isalpha(int v)
{
	if ((v >= 'a' && v <= 'z') || (v >= 'A' && v <= 'Z'))
		return (1);
	else
		return (0);
}

/**
*_atoi - converts a char to a number
*@h: the char to be converted
*Return: 0 if unsuccessful or the converted char
*/
int _atoi(char *h)
{
	int v, sign = 1, flag = 0, result;
	unsigned int final = 0;

	for (v = 0; h[v] != '\0' && flag != 2; v++)
	{
		if (h[v] == '-')
		{
			sign *= -1;
		}
		if (h[v] >= '0' && h[v] <= '9')
		{
			flag = 1;
			final *= 10;
			final += (h[v] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (sign == -1)
		result = -final;
	else
		result = final;
	return (result);
}
