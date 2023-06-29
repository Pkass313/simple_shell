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
