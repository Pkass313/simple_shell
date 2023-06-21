#include "shell.h"

/**
**_strncpy - will copy a string
*@dest: destination string will be copied to
*@src: the source string
*@o: amount of chars to copy
*Return: conjugated string
*/

char *_strncpy(char *dest, char *src, int o)

{
	int m, h;
	char *p = dest;

	m = 0;

	while (src[m] != '\0' && m < o - 1)
	
	{
		dest[m] = src[m];
		m++;
	}

	if (m < o)
	
	{
		h = m;
		
		while (h < o)

		{
			dest[h] = '\0';
			
		h++;
		}
	}
	
	return (p);
}

/**
**_strncat - conjugates two strings
*@dest: destination string will be copied to
*@src: source of the string
*@o: maximum bytes to be used
*Return: conjugated string
*/

char *_strncat(char *dest, char *src, int o)

{
	int m, h;
	char *p = dest;

	m = 0;

	h = 0;

	while (des[m] != '\0')

		m++;
	
	while (src[h] != '\0' && h < o)
	
	{
		dest[m] = src[h];

		m++;
		
		h++;
	}
	
	if (h < o)
		
		dest[m] = '\0';
	
	return (p);
}

/**
**_strchr - locates char in a string
*@p: string to parse
*@n: character to search for
*Return: (p) points to the memory area
*/

char *_strchr(char *p, char n)

{
	do {
		if (*p == n)
			return (p);
	} while (*p++ != '\0');
	
	return (NULL);
}
