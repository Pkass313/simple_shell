#include "shell.h"

/**
 *handle_signal- tracks interactive mode
 *@m: number to signal
 *Return: NULL
 */

void handle_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
