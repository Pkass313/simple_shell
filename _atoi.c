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
* Return: if true 1, if false 0
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
* Return: if p is alphabetic then 1, if not 0
*/

int _isalpha(int p)

{
	if ((c >= 'a' && p <= 'z') || (p >= 'A' && p <= 'Z'))
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
	int i, sign = 1, flag = 0, output;

	unsigned int result = 0;

	for (i = 0; q[i] != '\0' && flag != 2; i++)

	{
		if (q[i] == '-')
			sign *= -1;
		if (q[i] >= '0' && q[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (q[i] - '0');
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
