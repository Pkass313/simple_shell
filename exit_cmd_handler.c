#include "shell.h"

/**
* exit_cmd - exit command handler
* @command: command tokenizer
* @line: input line from stdin
*
* Return: NULL
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
* free_buffers - buffer freer
* @buf: buffer to be freed
*
* Return: NULL
*/
void free_buffers(char **buf)
{
	int o = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[o])
	{
		free(buf[o]);
		o++;
	}
	free(buf);
}
