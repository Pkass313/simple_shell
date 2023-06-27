#include "shell.h"

/**
 * _strcpy - A function that copies a string
 * @dest: The destination
 * @src: The source
 * Return: A pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int o = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[o])
	{
		dest[o] = src[o];
		o++;
	}
	dest[o] = 0;
	return (dest);
}

/**
 * _strdup - A function that duplicates a string
 * @str: Tthe string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int len = 0;
	char *ret;

	if (str == NULL)
		return (NULL);
	while (*str++)
		len++;
	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (NULL);
	for (len++; len--;)
		ret[len] = *--str;
	return (ret);
}

/**
 *_puts - A function that prints an input string
 *@str: The string
 * Return: No return
 */
void _puts(char *str)
{
	int o = 0;

	if (!str)
		return;
	while (str[o] != '\0')
	{
		_putchar(str[o]);
		o++;
	}
}

/**
 * _putchar - A function that writes the character c to stdout
 * @c: The character
 * Return: 1 (Success) otherwise return -1 and errno
 * is set appropriately
 */
int _putchar(char c)
{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || o >= WRITE_BUF_SIZE)
	{
		write(1, buf, o);
		o = 0;
	}
	if (c != BUF_FLUSH)
		buf[o++] = c;
	return (1);
}
