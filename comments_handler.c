#include "shell.h"

/**
 * _erratoi - A function that converts a string to an integer
 * @s: The string to convert
 * Return: 0 if no numbers in string are converted otherwise return -1
 */
int _erratoi(char *s)
{
	int o;
	unsigned long int result = 0;

	o = 0;
	if (*s == '+')
		s++;
	for (o = 0;  s[o] != '\0'; o++)
	{
		if (s[o] >= '0' && s[o] <= '9')
		{
			result *= 10;
			result += (s[o] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_error - A function that prints an error message
 * @info: The parameter
 * @estr: The string the specified error type
 * Return: 0 if no numbers in string are converted otherwise return -1
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * print_d - A function prints a decimal (integer) number (base 10)
 * @input: The input
 * @fd: The filedescriptor to write to
 * Return: The number of characters
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int o, count;
	unsigned int _abs_, curr;

	count = 0;
	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	curr = _abs_;
	for (o = 1000000000; o > 1; o /= 10)
	{
		if (_abs_ / o)
		{
			__putchar('0' + curr / o);
			count++;
		}
		curr %= o;
	}
	__putchar('0' + curr);
	count++;
	return (count);
}

/**
 * convert_number - A converter function, a clone of itoa
 * @num: The number
 * @base: The base
 * @flags: The argument flags
 * Return: The string
 */
char *convert_number(long int num, int base, int flags)
{
	static char *opt;
	static char buffer[50];
	char n;
	char *str;
	unsigned long z = num;

	n = 0;
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		z = -num;
		n = '-';
	}
	opt = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';
	do      {
		*--str = opt[z % base];
		z /= base;
	} while (z != 0);
	if (n)
		*--str = n;
	return (str);
}

/**
 * remove_comments -A function that replaces first instance of '#' with '\0'
 * @buf: The address of the string
 * Return: 0 (Success)
 */
void remove_comments(char *buf)
{
	int o;

	for (o = 0; buf[o] != '\0'; o++)
		if (buf[o] == '#' && (!o || buf[o - 1] == ' '))
		{
			buf[o] = '\0';
			break;
		}
}
