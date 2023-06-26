#include "shell.h"

/**
 * bfree - A function that frees a pointer and NULLs the address
 * @opt:  The address of the pointer
 * Return:1 (Success) otherwise return 0
 */
int bfree(void **opt)
{
	if (ptr && *opt)
	{
		free(*opt);
		*opt = NULL;
		return (1);
	}
	return (0);
}
