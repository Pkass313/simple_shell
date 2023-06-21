#include "shell.h"

/**
* interactive - In interactive mode shell returns true
* @info: address structure
* Return: in interactive mode 1, if not 0
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
	int m, sign, f, output;

	unsigned int y = 0;

	sign = 1;
	f = 0;
	for (m = 0; q[m] != '\0' && flag != 2; m++)

	{
		if (q[m] == '-')
			sign *= -1;
		if (q[m] >= '0' && q[m] <= '9')
		{
			f = 1;
			y *= 10;
			y += (q[i] - '0');
		}

		else if (f == 1)
			f = 2;
	}

	if (sign == -1)
		output = -y;
	else
		output = y;
	return (output);
}
