#include "shell.h"

/**
* append_path - path to command will be added
* @path: command path
* @command: command entered by user
*
* Return: On SUCCESS buffer containing command; otherwise NULL
*/
char *append_path(char *path, char *command)
{
	char *buf;
	size_t o = 0, z = 0;

	if (command == 0)
		command = "";

	if (path == 0)
		path = "";

	buf = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!buf)
		return (NULL);

	while (path[o])
	{
		buf[o] = path[o];
		o++;
	}

	if (path[o - 1] != '/')
	{
		buf[o] = '/';
		o++;
	}
	while (command[z])
	{
		buf[o + z] = command[z];
		z++;
	}
	buf[o + z] = '\0';
	return (buf);
}
