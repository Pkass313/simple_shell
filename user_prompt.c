#include "shell.h"

/**
* prompt_user - A function that prints $ for user to
* know the program is ready for input
* Description: If shell is in interactive mode, it prints
* the prompt
* Return: Nothing
*/
void prompt_user(void)
{
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		flags.interactive = 1;
	if (flags.interactive)
		write(STDERR_FILENO, "$ ", 2);
}
