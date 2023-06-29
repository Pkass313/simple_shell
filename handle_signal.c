#include "shell.h"

/**
 *handle_signal- it keeps track is interactive mode
 *@m: the signal number
 *Return: nothing
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
* find_path - finds the path from the global enviroment
* Return: NULL if path is not found or path if path is found.
*/
char *find_path(void)
{
	int x;
	char **env = environ, *path = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			path = *env;
			while (*path && x < 5)
			{
				path++;
				x++;
			}
			return (path);
		}
		env++;
	}
	return (NULL);
}
