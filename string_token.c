#include "shell.h"

/**
* **strtow - Ignores repeat delimiters and splits string into words
* @str: input string
* @b: delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *b)

{
	int m, h, l, n, numwords = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!b)
		b = " ";
	for (m = 0; str[m] != '\0'; m++)
		if (!is_delim(str[m], b) && (is_delim(str[m + 1], b) || !str[m + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);

	p = malloc((1 + numwords) * sizeof(char *));
	if (!p)
		return (NULL);
	for (m = 0, h = 0; h < numwords; h++)
	{
		while (is_delim(str[m], b))
			m++;
		l = 0;
		while (!is_delim(str[m + l], b) && str[m + l])

			l++;
		p[h] = malloc((l + 1) * sizeof(char));

		if (!p[h])
		{
			for (l = 0; l < h; l++)
				free(p[l]);
			free(p);
			return (NULL);
		}

		for (n = 0; n < l; n++)
			p[h][n] = str[m++];
		p[h][n] = 0;
	}
	p[h] = NULL;
	return (p);
}

/**
* **strtow2 - string splits into words
* @str: input string
* @b: delimeter
* Return: a points to array of strings, otherwise 0
*/

char **strtow2(char *str, char b)
{
	int m, h, l, n, numwords = 0;
	char **p;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (m = 0; str[m] != '\0'; m++)
		if ((str[m] != b && str[m + 1] == b) ||
				(str[m] != b && !str[m + 1]) || str[m + 1] == b)
			numwords++;
	if (numwords == 0)
		return (NULL);
	p = malloc((1 + numwords) * sizeof(char *));
	if (!p)
		return (NULL);
	for (m = 0, h = 0; h < numwords; h++)

	{
		while (str[m] == b && str[m] != b)
			m++;
		l = 0;
		while (str[m + l] != b && str[m + l] && str[m + l] != b)
			l++;
		p[h] = malloc((l + 1) * sizeof(char));
		if (!p[h])
		{
			for (l = 0; l < h; l++)
				free(p[l]);
			free(p);
			return (NULL);
		}
		for (n = 0; n < l; n++)
			p[h][n] = str[m++];
		p[h][n] = 0;

	}
	p[h] = NULL;

	return (p);
}
