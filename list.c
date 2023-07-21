#include "main.h"
/**
*add_node - adds node
*@head: address of the pointer
*@str: the string
*@num: the number
*Return: size of list
*/
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
*add_node_end - adds a node to the end
*@head: parameter struct
*@str: parameter struct
*@num: the number
*Return: size of list
*/
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node;
	list_t *node;

	if (!head)
		return (NULL);
	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head  = new_node;
	return (new_node);
}

/**
*print_list_str - prints the str element
*@x: pointer to node
*Return: size of the list
*/
size_t print_list_str(const list_t *x)
{
	size_t v = 0;

	while (x)
	{
		_puts(x->str ? x->str : "(nil)");
		_puts("\n");
		x = x->next;
		v++;
	}
	return (v);
}

/**
*delete_node_at_index - deletes node at index
*@head: parameter
*@index: parameter
*Return: 1 on success 0 on error
*/
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node;
	list_t *prev_node;
	unsigned int v = 0;

	if (!head || !*head)
		return (0);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (v == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		v++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
*free_list - frees a list
*@head_ptr: parameter struct
*Return: nothing
*/
void free_list(list_t **head_ptr)
{
	list_t *node, *next_node, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_ptr = NULL;
}
