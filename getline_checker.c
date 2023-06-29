#include "shell.h"
/**
 *checker- checks for built-in function
 *@cmd: user input tokenizer
 *@buf: derived from getline function
 *Return: On SUCCESS 1 if cmd excuted; NULL if cmd is not executed
 */
int checker(char **cmd, char *buf)
{
	if (handle_builtin(cmd, buf))
		return (1);
	else if (**cmd == '/')
	{
		execution(cmd[0], cmd);
		return (1);
	}
	return (0);
}
