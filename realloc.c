#include "shell.h"

/**
 * _memset - A function that  fills memory with a constant byte
 * @s: The pointer
 * @b: The byte to fill *s with
 * @n: The number of byte
 * Return: A pointer to the memory area s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int t;

	for (t = 0; t < n; t++)
		s[t] = b;
	return (s);
}

/**
 * ffree - A function that frees a string of strings
 * @cc: string of strings
 */
void ffree(char **cc)
{
	char **o = cc;

	if (!cc)
		return;
	while (*cc)
		free(*cc++);
	free(o);
}

/**
 * _realloc - A function that reallocates a block of memory
 * @opt: The pointer
 * @old_size: The byte size of previous block
 * @new_size: The byte size of new block
 * Return: The pointer to da ol'block nameen
 */
void *_realloc(void *opt, unsigned int old_size, unsigned int new_size)
{
	char *k;

	if (!opt)
		return (malloc(new_size));
	if (!new_size)
		return (free(opt), NULL);
	if (new_size == old_size)
		return (opt);
	k = malloc(new_size);
	if (!k)
		return (NULL);
	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		k[old_size] = ((char *)opt)[old_size];
	free(opt);
	return (k);
}
