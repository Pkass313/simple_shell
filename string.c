#include "shell.h"

/**
* _strcmp - A function that compares two strings
* @s1: The first string
* @s2: The second string
* Return: The difference between strings
*/
int _strcmp(char *s1, char *s2)
{
	int k = 0, output;

	while (*(s1 + k) == *(s2 + k) && *(s1 + k) != '\0')
		k++;

	output = (*(s1 + k) - *(s2 + k));

	return (output);
}

/**
* _strlen - A function that returns the length of a string
* @s: The string
* Return: The length of the string
*/
int _strlen(char *s)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}

/**
* _strncmp - A function that compares two strings up to n bytes
* @s1: The first string
* @s2: The second string
* @n: The number of bytes
* Return: The difference between s1 and s2
*/
int _strncmp(char *s1, char *s2, int n)
{
	int o;

	for (o = 0; s1[o] && s2[o] && o < n; o++)
	{
		if (s1[o] != s2[o])
			return (s1[o] - s2[o]);
	}
	return (0);
}

/**
* _strdup - A function that dupicates string
* @s: The character
* Return: A pointer
*/
char *_strdup(char *s)
{
	char *ptr;
	int o, len;

	if (s == NULL)
		return (NULL);

	len = _strlen(s);

	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	for (o = 0; *s != '\0'; s++, o++)
		ptr[o] = s[0];

	ptr[o++] = '\0';
	return (ptr);
}

/**
* _strchr - A function that locates a character in a string
* @s: The string
* @c: The character
* Return: A pointer otherwise return NULL
*/
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (!c)
		return (s);
	return (NULL);
}
