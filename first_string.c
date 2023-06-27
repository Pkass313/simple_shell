#include "shell.h"

/**
* _strlen - length of a string
* @s: string length to check
*
* Return: length interger of string
*/

int _strlen(char *s)
{
	int o = 0;

	if (!s)
		return (0);
	while (*s++)
		o++;
	return (o);
}

/**
* _strcmp - executes comparison of two strings
* @s1: first string
* @s2: second string
*
* Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
* starts_with - will check needle starts with haystack
* @haystack: string to look up
* @needle: the substring to locate
*
* Return: address of next characater of haystack or 0
*/

char *starts_with(const char *haystack, const char *needle)

{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
* _strcat - conjugates two strings
* @dest: destination of buffer
* @src: source of buffer
*
* Return: points to destination buffer
*/

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
