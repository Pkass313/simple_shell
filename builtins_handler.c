#include "shell.h"

/**
* handle_builtin - executes builtin functions
* @command: command tokenizer
* @line: input from stdin
*
* Return: on SUCCESS 1 if executed, NULL if not
*/
int handle_builtin(char **command, char *line)
{
	struct builtin builtin = {"env", "exit"};

	if (_strcmp(*command, builtin.env) == 0)
	{
		print_env();
		return (1);
	}
	else if (_strcmp(*command, builtin.exit) == 0)
	{
		exit_cmd(command, line);
		return (1);
	}
	return (0);
}
