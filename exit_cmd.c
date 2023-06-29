#include "shell.h"

/**
* exit_cmd - handles the exit command
* @command: tokenized command
* @line: input read from stdin
*
* Return: no return
*/
void exit_cmd(char **command, char *line)
{
	free(line);
	free_buffers(command);
	exit(0);
}
free_function.c
#include "shell.h"

/**
* free_buffers - frees buffers
* @buf: buffer to be freed
*
* Return: no return
*/
void free_buffers(char **buf)
{
	int i = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[i])
	{
		free(buf[i]);
		i++;
	}
	free(buf);
}
