#include "shell.h"
/**
* test_path - A function that checks if path is valid
* @path: The path
* @command: Command entered by user
* Return: path (Success) otherwise return NULL
*/
char *test_path(char **path, char *command)
{
	int k;
	char *output;

	k = 0;
	while (path[k])
	{
		output = append_path(path[k], command);
		if (access(output, F_OK | X_OK) == 0)
			return (output);
		free(output);
		k++;
	}
	return (NULL);
}
