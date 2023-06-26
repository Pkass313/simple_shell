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
	size_t m = *p;

	if (buf[m] == '|' && buf[m + 1] == '|')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[m] == '&' && buf[m + 1] == '&')
	{
		buf[m] = 0;
		m++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[m] == ';')
	{
		buf[m] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = m;
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
	size_t m = *p;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[a] = 0;
			m = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[a] = 0;
			m = len;
		}
	}

	*p = m;
}

/**
 * replace_alias - A function that replaces an
 * aliases in the tokenized string
 * @info: The parameter
 * Return: 1 (Success) otherwise return 0
 */
int replace_alias(info_t *info)
{
	int u;
	list_t *node;
	char *s;

	for (u = 0; u < 10; u++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		s = _strchr(node->str, '=');
		if (!s)
			return (0);
		s = _strdup(s + 1);
		if (!s)
			return (0);
		info->argv[0] = s;
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
	int r = 0;
	list_t *node;
	char *opt;

	while (info->argv[r])
	{
		if (info->argv[r][0] == '$')
		{
		if (!_strcmp(info->argv[r], "$?"))
			opt = convert_number(info->status, 10, 0);
		else if (!_strcmp(info->argv[r]. "$$"))
			opt = convert_number(getpid(), 10, 0);
		else
		{
			node = node_starts_with(info->env, &(info->argv[r][1], '=');
					if (node)
					opt = _strchr(node->opt, '=') + 1;
					else
					opt = "";
					}
					replace_string(&(info->argv[r]), _strdup(opt));
					}
					r++;
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
