#include "shell.h"
/**
* tokenizer -A function that creates tokens from given input
* @line: The line to be tokenized
* Return: An array of strings
*/
char **tokenizer(char *line)
{
	char *buf = NULL, *bufp = NULL, *token = NULL, *delim = " :\t\r\n";
	char **tokens = NULL;
	int tokensize;
	size_t index = 0, f = 0;

	tokensize = 1;
	buf = _strdup(line);
	if (!buf)
		return (NULL);
	bufp = buf;

	while (*bufp)
	{
		if (_strchr(delim, *bufp) != NULL && f == 0)
		{
			tokensize++;
			f = 1;
		}
		else if (_strchr(delim, *bufp) == NULL && f == 1)
			f = 0;
		bufp++;
	}
	tokens = malloc(sizeof(char *) * (tokensize + 1));
	token = strtok(buf, delim);
	while (token)
	{
		tokens[index] = _strdup(token);
		if (tokens[index] == NULL)
		{
			free(tokens);
			return (NULL);
		}
		token = strtok(NULL, delim);
		index++;
	}
	tokens[index] = '\0';
	free(buf);
	return (tokens);
}
