#include "main.h"
/**
***strtow - splits a string to words
*@str: input string
*@d: delimeter
*Return: a pointer to the string
*/
char **strtow(char *str, char *d)
{
	int v, w, x, y, numbers = 0;
	char **u;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (v = 0; str[v] != '\0'; v++)
		if (!is_delim(str[v], d) && (is_delim(str[v + 1], d) || !str[v + 1]))
			numbers++;
	if (numbers == 0)
		return (NULL);
	u = malloc((1 + numbers) * sizeof(char *));
	if (!u)
		return (NULL);
	for (v = 0, w = 0; w < numbers; w++)
	{
		while (is_delim(str[v + x], d) && str[v + x])
			x++;
		u[w] = malloc((x + 1) * sizeof(char *));
		if (!u[w])
		{
			for (x = 0; x < w; x++)
				free(u[x]);
			free(u);
			return (NULL);
		}
		for (y = 0; y < x; y++)
			u[w][y] = str[v++];
		u[w][y] = 0;
	}
	u[w] = NULL;
	return (u);
}

/**
**strtow2 - splits an str into 2
*@str: input str
*@d: delimeter
*Return: ptr or null on failure
*/
char **strtow2(char *str, char d)
{
	int u, v, w, x, numbers = 0;
	char **y;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (u = 0; str[u] != '\0'; u++)
		if ((str[u] != d && str[u + 1] == d) ||
				(str[u] != d && str[u + 1]) || str[u + 1] == d)
			numbers++;
	if (numbers == 0)
		return (NULL);
	y = malloc((1 + numbers) * sizeof(char *));
	if (!y)
		return (NULL);
	for (u = 0, v = 0; v < numbers; v++)
	{
		while (str[u] == d && str[u] != d)
			u++;
		w = 0;
		while (str[u + w] != d && str[u + w] && str[u + w] != d)
			w++;
		y[v] = malloc((w + 1) * sizeof(char *));
		if (!y[v])
		{
			for (w = 0; w < v; w++)
				free(y[w]);
			free(y);
			return (NULL);
		}
		for (x = 0; x < w; x++)
			y[v][x] = str[u++];
		y[v][w] = 0;
	}
	y[v] = NULL;
	return (y);
}
