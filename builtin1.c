#include "main.h"
/**
*_myhistory - displays the history list
*@info: contains potential arguments
*Return: nothing
*/
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}

/**
*unset_alias - sets the alias to str
*@info: contains potential args
*@str: the string
*Return: 0 if successful 1 if otherwise
*/
int unset_alias(info_t *info, char *str)
{
	char *v, w;
	int ret;
	
	v = _strchr(str, '=');
	if (!v)
		return (1);
	w = *v;
	*v = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*v = w;
	return (ret);
}

/**
*set_alias - sets the alias to str
*@info: contains the potential args
*@str: the string
*Return: 0 if success 1 if otherwise
*/
int set_alias(info_t *info, char *str)
{
	char *a;

	a = _strchr(str, '=');
	if (!a)
		return (1);
	if (!*++a)
		return (set_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
*print_alias - prints an alias str
*@node: a parameter
*Return: 0 if successful 1 if otherwise
*/
int print_alias(list_t *node)
{
	char *b = NULL, *x = NULL;

	if (node)
	{
		b = _strchr(node->str, '=');
		for (x = node->str; x <= b; x++)
			_putchar(*x);
		_putchar('\'');
		_puts(b + 1);
		_puts("\n");
		return (0);
	}
	return (1);
}

/**
*_myalias - resembles the builtin alias
*@info: parameter
*Return: nothing
*/
int _myalias(info_t *info)
{
	int v = 0;
	char *s = NULL;
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
	for (v = 1; info->arg[v]; v++)
	{
		s = _strchr(info->argv[v], '=');
		if (s)
			set_alias(info, info->argv[v]);
		else
			print_alias(node_starts_with(info->alias, info->argv[v], '='));
	}
	return (0);
}
