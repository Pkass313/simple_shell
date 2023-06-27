#include "shell.h"

/**
* get_environ - outcome string array copy of our environ
* @info: Structure of potential arguments
* maintains constant function prototype.
* Return: Always 0
*/

char **get_environ(info_t *info)

{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}
	return (info->environ);
}

/**
* _unsetenv - Removes environment variable
* @info: Structure of potential arguments
* Maintains constant function prototype.
* Return: 1 on delete, 0 otherwise
* @var: string environmenty and variable property
*/

int _unsetenv(info_t *info, char *var)

{
	list_t *node = info->env;
	size_t o = 0;
	char *m;

	if (!node || !var)
		return (0);
	while (node)
	{
		m = starts_with(node->str, var);
		if (m && *m == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), o);
			o = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		o++;
	}
	return (info->env_changed);
}

/**
* _setenv - Will initiate a new env var or change an existing one
* @info: Struct of potential arguments
* Maintains constant function prototype.
* @var: environment variable property of environment
* @value: value of the string environment variable
*  Return: Always 0
*/

int _setenv(info_t *info, char *var, char *value)

{
	char *buf = NULL;
	list_t *node;
	char *m;

	if (!var || !value)
		return (0);
	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
	s = starts_with(node->str, var);
	if (m && *m == '=')
	{
		free(node->str);
		node->str = buf;
		info->env_changed = 1;
		return (0);
	}
	node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}
