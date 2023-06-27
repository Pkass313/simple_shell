#include "shell.h"

/**
* interactive - In interactive mode shell returns true
* @info: address structure
* Return: in interactive mode 2, if not 0
*/

int interactive(info_t *info)

{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}


/**
* is_delim - checks if char is a delimeter
* @c: Char to be checked
* @delim: string of delimeter
* Return: 1 (Success) otherwise return 0
*/

int is_delim(char c, char *delim)

{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
* _isalpha - alphabetic char checker
* @c: Char to insert
* Return: if p is alphabetic return 1, otherwise return 0
*/

int _isalpha(int c)

{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}


/**
* _atoi - changes a string to an integer
* @s: string to convert
* Return: if no nums in string 0, if not converted num
*/

int _atoi(char *s)

{
	int o, sign = 1, flag = 0, output;

	unsigned int result = 0;

	sign = 1;
	flag = 0;
	for (o = 0; s[o] != '\0' && flag != 2; o++)

	{
		if (s[o] == '-')
			sign *= -1;
		if (s[o] >= '0' && s[o] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[o] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;
	return (output);
}
