#include "shell.h"

/**
* find_path - A function that finds the path from the global enviroment
* Return: If path not found, return NULL
*/
char *find_path(void)
{
	int k;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && k < 5)
			{
				path++;
				k++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
