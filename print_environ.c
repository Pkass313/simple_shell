#include "shell.h"

/**
 * _myenv - A function that prints the current environment
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _myenv(info_t *info)
{
	print_list_str(info->env);
	return (0);
}

/**
 * _getenv - A function that gets the value of an environ variable
 * @info: Structure containing potential arguments
 * @name: The env variable
 * Return: The value
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *n = info->env;
	char *o;

	while (n)
	{
		o = starts_with(n->str, name);
		if (o && *o)
			return (o);
		n = n->next;
	}
	return (NULL);
}

/**
 * _mysetenv - A function that initializes a new environment variable
 * or modify an existing one
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - A function that removes an environment variable
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _myunsetenv(info_t *info)
{
	int y;

	if (info->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (y = 1; y <= info->argc; y++)
		_unsetenv(info, info->argv[y]);
	return (0);
}

/**
 * populate_env_list - A function that populates env linked list
 * @info: Structure containing potential arguments
 * Return: Always 0
 */
int populate_env_list(info_t *info)
{
	list_t *node = NULL;
	size_t k;

	for (k = 0; environ[k]; k++)
		add_node_end(&node, environ[k], 0);
	info->env = node;
	return (0);
}