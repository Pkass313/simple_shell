#include "shell.h"

/**
* **strtow - Ignores repeat delimiters and splits string into words
* @str: input string
* @d: delimeter string
* Return: a pointer to an array of strings, or NULL on failure
*/

char **strtow(char *str, char *d)

{
	int o, z, x, u, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (o = 0; str[o] != '\0'; o++)
		if (!is_delim(str[o], d) && (is_delim(str[o + 1], d) || !str[o + 1]))
			numwords++;
	if (numwords == 0)
		return (NULL);

	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (o = 0, z = 0; z < numwords; z++)
	{
		while (is_delim(str[o], d))
			o++;
		x = 0;
		while (!is_delim(str[o + x], d) && str[o + x])

			x++;
		t[z] = malloc((x + 1) * sizeof(char));

		if (!t[z])
		{
			for (x = 0; x < z; x++)
				free(t[x]);
			free(t);
			return (NULL);
		}

		for (u = 0; u < x; u++)
			t[z][u] = str[o++];
		t[z][u] = 0;
	}
	t[z] = NULL;
	return (t);
}

/**
* **strtow2 - string splits into words
* @str: input string
* @d: delimeter
* Return: a points to array of strings, otherwise 0
*/

char **strtow2(char *str, char d)
{
	int o, z, x, u, numwords = 0;
	char **t;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (o = 0; str[o] != '\0'; o++)
		if ((str[o] != d && str[o + 1] == d) ||
				(str[o] != d && !str[o + 1]) || str[o + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	t = malloc((1 + numwords) * sizeof(char *));
	if (!t)
		return (NULL);
	for (o = 0, z = 0; z < numwords; z++)

	{
		while (str[o] == d && str[o] != d)
			o++;
		x = 0;
		while (str[o + x] != d && str[o + x] && str[o + x] != d)
			x++;
		t[z] = malloc((x + 1) * sizeof(char));
		if (!t[z])
		{
			for (x = 0; x < z; x++)
				free(t[x]);
			free(t);
			return (NULL);
		}
		for (u = 0; u < x; u++)
			t[z][u] = str[o++];
		t[z][u] = 0;

	}
	t[z] = NULL;

	return (t);
}
