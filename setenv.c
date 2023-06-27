#include "shell.h"

/**
**_strncpy - will copy a string
*@dest: destination string will be copied to
*@src: the source string
*@n: amount of chars to copy
*Return: conjugated string
*/

char *_strncpy(char *dest, char *src, int n)

{
	int o, z;
	char *t = dest;

	o = 0;
	while (src[o] != '\0' && o < n - 1)

	{
		dest[o] = src[o];
		o++;
	}

	if (o < n)

	{
		z = o;
		while (z < n)

		{
			dest[z] = '\0';

			z++;
		}
	}

	return (t);
}

/**
**_strncat - conjugates two strings
*@dest: destination string will be copied to
*@src: source of the string
*@n: maximum bytes to be used
*Return: conjugated string
*/

char *_strncat(char *dest, char *src, int n)

{
	int o, z;
	char *t = dest;

	o = 0;
	z = 0;

	while (dest[o] != '\0')

		o++;

	while (src[z] != '\0' && z < n)
	{
		dest[o] = src[z];
		o++;
		z++;
	}

	if (z < n)
		dest[o] = '\0';

	return (t);
}

/**
**_strchr - locates char in a string
*@s: string to parse
*@c: character to search for
*Return: (s) points to the memory area
*/

char *_strchr(char *s, char c)

{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
