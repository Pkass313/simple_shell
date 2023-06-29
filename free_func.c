#include "shell.h"

/**
* free_buffers - A function that frees buffers
* @buf: The buffer
* Return: Nothing
*/
void free_buffers(char **buf)
{
	int o = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[o])
	{
		free(buf[o]);
	}
	free(buf);
}
