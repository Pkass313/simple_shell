#include "shell.h"

/**
 *handle_signal- tracks interactive mode
 *@m: number to signal
 *Return: NULL
 */

void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
path.c
#include "shell.h"

/**
* find_path - path from the global enviroment locater
* Return: NULL if path not found, otherwise PATH if path is found.
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
