#include "shell.h"

/**
 * is_chain - A function that test if current
 * char in buffer is a chain delimeter
 * @info: The parameter
 * @buf: The character
 * @p: The address
 * Return: 1 (Success) otherwise return 0
 */
int is_chain(info_t *info, char *buf, size_t *p)
{
	size_t z = *p;

	if (buf[z] == '|' && buf[z + 1] == '|')
	{
		buf[z] = 0;
		z++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[z] == '&' && buf[z + 1] == '&')
	{
		buf[z] = 0;
		z++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[z] == ';')
	{
		buf[z] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = z;
	return (1);
}

/**
 * check_chain - A function that checks whether or not to
 * continue chaining based on last status
 * @info: The parameter
 * @buf: The character
 * @p: The address
 * @a: The starting point
 * @len: The length of buf
 * Return: Void
 */
void check_chain(info_t *info, char *buf, size_t *p, size_t a, size_t len)
{
	size_t z = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[a] = 0;
			z = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[a] = 0;
			z = len;
		}
	}

	*p = z;
}

/**
 * replace_alias - A function that replaces an
 * aliases in the tokenized string
 * @info: The parameter
 * Return: 1 (Success) otherwise return 0
 */
int replace_alias(info_t *info)
{
	int o;
	list_t *node;
	char *m;

	for (o = 0; o < 10; o++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		m = _strchr(node->str, '=');
		if (!m)
			return (0);
		m = _strdup(m + 1);
		if (!m)
			return (0);
		info->argv[0] = m;
	}
	return (1);
}

/**
 * replace_vars - A function that replaces
 * vars in the tokenized string
 * @info: The parameter
 * Return: 1 (Success) otherwise return 0
 */
int replace_vars(info_t *info)
{
	int o;
	list_t *node;

	o = 0;
	for (o = 0; info->argv[o]; o++)
	{
		if (info->argv[o][0] != '$' || !info->argv[o][1])
			continue;
		if (!_strcmp(info->argv[o], "$?"))
		{
			replace_string(&(info->argv[o]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[o], "$$"))
		{
			replace_string(&(info->argv[o]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[o][1], '=');
		if (node)
		{
			replace_string(&(info->argv[o]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[o], _strdup(""));
	}
	return (0);
}

/**
 * replace_string - A function that replaces string
 * @old: The address
 * @new: The new string
 * Return: 1 (Success) otherwise return 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
