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
	char *m, d;
	int ret;

	m = _strchr(str, '=');

	if (!m)

		return (1);

	d = *m;
	*m = 0;
	ret = delete_node_at_index(&(info->alias),
			get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*m = d;

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
	char *m;

	m = _strchr(str, '=');

	if (!m)

		return (1);

	if (!*++m)

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
	char *m = NULL, *e = NULL;

	if (node)

	{
		m = _strchr(node->str, '=');

		for (e = node->str; e <= m; e++)

			_putchar(*e);
		_putchar('\'');
		_puts(m + 1);
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
	char *m = NULL;
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

	for (o = 1; info->argv[o]; o++)
	{
		m = _strchr(info->argv[o], '=');

		if (m)
			set_alias(info, info->argv[o]);
		else
			print_alias(node_starts_with(info->alias, info->argv[o], '='));
	}
	return (0);
}
