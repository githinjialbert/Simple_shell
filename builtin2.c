#include "main.h"
/**
*_myhistory - displays the history
*@info: parameter
*Return: 0
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
*unset_alias - unsets the allias
*@info: paarameter
*@str: the stirng
*Return: 0 if good 1 if not
*/
int unset_alias(info_t *info, char *str)
{
	char *q, v;
	int ret;

	q = _strchr(str, '=');
	if (!q)
		return (1);
	v = *q;
	*q = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*q = v;
	return (ret);
}

/**
*set_alias - sets the alias
*@info: parameter
*@str: string
*Return: 0 if success -1 if not
*/
int set_alias(info_t *info, char *str)
{
	char *x;

	x = _strchr(str, '=');
	if (!x)
		return (1);
	if (!*++x)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
*print_alias - prints the alias
*@node: the node
*Return: 0 if correct 1 if not
*/
int print_alias(list_t *node)
{
	char *v = NULL, *x = NULL;

	if (node)
	{
		v = _strchr(node->str, '=');
		for (x = node->str; x <= v; x++)
			_putchar(*x);
		_putchar('\'');
		_puts(v + 1);
		_puts("\n");
		return (0);
	}
	return (1);
}

/**
*_myalias - resembles the alias butteon
*@info: parameter
*Return: 0
*/
int _myalias(info_t *info)
{
	int x = 0;
	char *v = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		v = _strchr(info->argv[x], '=');
		if (v)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
