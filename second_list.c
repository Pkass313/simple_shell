#include "shell.h"

/**
* list_len - will display length of linked list
* @h: points to first node
*
* Return: size of list
*/

size_t list_len(const list_t *h)
{
	size_t o = 0;

	while (h)
	{
		h = h->next;
		o++;
	}
	return (o);
}

/**
* list_to_strings - produces an array of strings from the list->str
* @head: will point to first node
*
* Return: array of strings
*/

char **list_to_strings(list_t *head)

{
	list_t *node = head;
	size_t o = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !o)
		return (NULL);
	strs = malloc(sizeof(char *) * (o + 1));
	if (!strs)
		return (NULL);
	for (o = 0; node; node = node->next, o++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < o; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = _strcpy(str, node->str);
		strs[o] = str;
	}
	strs[o] = NULL;
	return (strs);
}

/**
* print_list - all elements on a list_t linked list  will print
* @h: points to first node
*
* Return: size of list
*/

size_t print_list(const list_t *h)

{
	size_t o = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		o++;
	}
	return (o);
}

/**
* node_starts_with - node with string starting with prefix returns
* @node: points to list head
* @prefix: complementing string
* @c: char after complementing prefix
*
* Return: match node or null
*/

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *m = NULL;

	while (node)
	{
		m = starts_with(node->str, prefix);
		if (m && ((c == -1) || (*m == c)))
			return (node);
		node = node->next;
	}

	return (NULL);
}

/**
* get_node_index - collects index of a node
* @head: points to list head
* @node: points to the node
*
* Return: index of node or -1
*/

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t o = 0;

	while (head)
	{
		if (head == node)
			return (o);
		head = head->next;
		o++;
	}
	return (-1);
}
