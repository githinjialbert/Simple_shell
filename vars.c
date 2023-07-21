#include "main.h"
/**
*is_chain - tests for a chain delimiter
*@info: parameter
*@buf: buffer
*@p: address of the curr pos
*Return: 1 if successful 0 if otherwise
*/
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t v = *p;

	if (buf[v] == '|' && buf[v + 1] == '|')
	{
		buf[v] = 0;
		v++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[v] == ';')
	{
		buf[v] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = v;
	return (1);
}

/**
*check_chain - continues checking based on the last return
*@info: parameter
*@buf: buffer
*@p: address of the curr pos
*@i: starting pos
*@len: length of the buf
*Return: nothing
*/
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
{
	size_t v = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			v = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			v = len;
		}
	}
	*p = v;
}

/**
*replace_vars - replaces variables
*@info: parameter
*Return: 1 if successful 0 otherwise
*/
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(""));
	}
	return (0);
}

/**
*replace_string - replaces a string
*@old: the old str
*@new: the new str
*Return: 1 if successful 0 if otherwise
*/
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}

/**
*replace_alias - replaces aliases
*@info: parameter
*Return: 1 if successful 0 if otherwise
*/
int replace_alias(info_t *info)
{
	int v;
	list_t *node;
	char *a;

	for (v = 0; v < 10; v++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		a = _strchr(node->str, '=');
		if (!a)
			return (0);
		info->argv[0] = a;
	}
	return (1);
}
