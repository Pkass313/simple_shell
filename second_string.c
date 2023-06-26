#include "shell.h"

/**
 * _strcpy - A function that copies a string
 * @dest: The destination
 * @src: The source
 * Return: A pointer to the destination
 */
char *_strcpy(char *dest, char *src)
{
	int l = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[l])
	{
		dest[l] = src[l];
		l++;
	}
	dest[l] = 0;
	return (dest);
}

/**
 * _strdup - A function that duplicates a string
 * @str: Tthe string to duplicate
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int o = 0;
	char *tmp;

	if (str == NULL)
		return (NULL);
	while (*str++)
		o++;
	tmp = malloc(sizeof(char) * (o + 1));
	if (!tmp)
		return (NULL);
	for (o++; o--;)
		tmp[o] = *--str;
	return (tmp);
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
	static int k;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || k >= WRITE_BUF_SIZE)
	{
		write(1, buf, k);
		k = 0;
	}
	if (c != BUF_FLUSH)
		buf[k++] = c;
	return (1);
}
