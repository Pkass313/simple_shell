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
* @p: Char to be checked
* @delim: string of delimeter
* Return: 1 (Success) otherwise return 0
*/

int is_delim(char p, char *delim)

{
	while (*delim)
		if (*delim++ == p)
			return (1);
	return (0);
}

/**
* _isalpha - alphabetic char checker
* @p: Char to insert
* Return: if p is alphabetic return 1, otherwise return 0
*/

int _isalpha(int p)

{
	if ((p >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
		return (1);
	else
		return (0);
}


/**
* _atoi - changes a string to an integer
* @q: string to convert
* Return: if no nums in string 0, if not converted num
*/

int _atoi(char *q)

{
	int o, sign = 1, flag = 0, output;

	unsigned int y = 0;

	sign = 1;
	flag = 0;
	for (o = 0; q[o] != '\0' && flag != 2; o++)

	{
		if (q[o] == '-')
			sign *= -1;
		if (q[o] >= '0' && q[o] <= '9')
		{
			flag = 1;
			y *= 10;
			y += (q[o] - '0');
		}

		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -y;
	else
		output = y;
	return (output);
}
