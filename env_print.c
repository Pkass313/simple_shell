#include "shell.h"

/**
* print_env - environment string printed to stdout
*
* Return: NULL
*/
void print_env(void)
{
	int k = 0;
	char **env = environ;

	while (env[k])
	{
		write(STDOUT_FILENO, (const void *)env[k], _strlen(env[k]));
		write(STDOUT_FILENO, "\n", 1);
		k++;
	}
}
