#include "shell.h"

/**
 * add_node - A function that adds a node at the start of the list
 * @head: The haed
 * @str: str field of node
 * @num: The node index
 * Return: The size of list
 */
list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *new_head;

	if (!head)
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
 * add_node_end - A function that adds a node to the end of the list
 * @head: The head
 * @str: str field of node
 * @num: The node index
 * Return: The address of the new element otherwise return NULL
 */
list_t *add_node_end(list_t **head, const char *str, int num)
{
	list_t *new_node, *last;

	if (!head)
		return (NULL);
	last = *head;
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
	if (last)
	{
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - A function that prints only the str
 * element of a list_t linked list
 * @h: The pointer
 * Return: The size of the list
 */
size_t print_list_str(const list_t *h)
{
	size_t o;

	o = 0;
	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		o++;
	}
	return (o);
}

/**
 * delete_node_at_index - A function that deletes node at given index
 * @head: The head
 * @index: The index of the node
 * Return: 1 (Success) otherwise return 0
 */
int delete_node_at_index(list_t **head, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int o;

	o = 0;
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
		if (o == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		o++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - A function that frees all nodes of a list
 * @head_opt: The address of pointer to head node
 * Return: void
 */
void free_list(list_t **head_opt)
{
	list_t *node, *next_node, *h;

	if (!head_opt || !*head_opt)
		return;
	h = *head_opt;
		node = h;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*head_opt = NULL;
}
