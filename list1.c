#include "main.h"
/**
*list_len - determines the length of the list
*@h: pointer
*Return: size of list
*/
size_t list_len(const list_t *h)
{
	size_t v = 0;

	while (h)
	{
		h = h->next;
		v++;
	}
	return (v);
}

/**
*list_to_strings - returns an array of strs
*@head: pointer
*Return: sizeof list
*/
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t v = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !v)
		return (NULL);
	strs = malloc(sizeof(char *) * (v + 1));
	if (!strs)
		return (NULL);
	for (v = 0; node; node = node->next, v++)
	{
		if (!str)
		{
			for (j = 0; j < v; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[v] = str;
	}
	strs[v] = NULL;
	return (strs);
}

/**
*print_list - prints elements of the list
*@h: pointer
*Return: size of list
*/
size_t print_list(const list_t *h)
{
	size_t v = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		v++;
	}
	return (v);
}

/**
*node_starts_with - returns node of an str starting with a prefix
*@node: pointer
*@prefix: parameter
*@c: the next char
*Return: node or null
*/
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *x = NULL;

	while (node)
	{
		x = starts_with(node->str, prefix);
		if (x && ((c == -1) || (*x == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
*get_node_index - gets the node of an index
*@head: parameter
*@node: pointer
*Return: node index or -1 if failure
*/
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t v = 0;

	while (head)
	{
		if (head == node)
		{
			return (v);
		}
		head = head->next;
		v++;
	}
	return (-1);
}
