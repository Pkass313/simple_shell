#include "shell.h"

/**
* _myhistory - shows history list, preceded line by line
* line nums start at 0
* @info: contains potential arguments
* Maintains constant function prototype
* Return: Always 0
*/

int _myhistory(info_t *info)

{
	print_list(info->history);

	return (0);
}

/**
* unset_alias - alias set to string
* @info: structure of parameters
* @str: alias string
* Return: Always 0 on success, 1 on error
*/

int unset_alias(info_t *info, char *str)

{
	char *g, n;
	int ret;

	g = _strchr(str, '=');

	if (!g)

		return (1);

	n = *g;
	*g = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*g = n;

	return (ret);
}
/**
* set_alias - alias set to string
* @info: structure of parameters
* @str: alias string
* Return: Always 0 on success, 1 on error
*/

int set_alias(info_t *info, char *str)

{
	char *g;

	g = _strchr(str, '=');

	if (!g)

		return (1);

	if (!*++g)

		return (unset_alias(info, str));

	unset_alias(info, str);

	return (add_node_end(&(info->alias), str, 0) == NULL);
}

/**
* print_alias - alias string wil print
* @node: node of alias
* Return: Always 0 on success, 1 on error
*/

int print_alias(list_t *node)

{
	char *g = NULL, *e = NULL;

	if (node)

	{
		g = _strchr(node->str, '=');

		for (e = node->str; e <= g; e++)

			_putchar(*e);
		_putchar('\'');
		_puts(g + 1);
		_puts("'\n");

		return (0);
	}

	return (1);
}

/**
* _myalias - mirrors builtin alias
* @info: Contains potential arguments
* Maintains constant function prototype.
*  Return: Always 0
*/

int _myalias(info_t *info)

{
	int m = 0;
	char *g = NULL;
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

	for (m = 1; info->argv[m]; m++)
	{
		g = _strchr(info->argv[m], '=');

		if (g)
			set_alias(info, info->argv[m]);
		else
			print_alias(node_starts_with(info->alias, info->argv[m], '='));
	}
	return (0);
}
