#include "shell.h"

/**
 * _erratoi - A function that converts a string to an integer
 * @s: The string to convert
 * Return: 0 if no numbers in string are converted otherwise return -1
 */
int _erratoi(char *s)
{
	int d;
	unsigned long int t = 0;

	d = 0;
	if (*s == '+')
		s++;
	for (d = 0;  s[d] != '\0'; d++)
	{
		if (s[d] >= '0' && s[d] <= '9')
		{
			t *= 10;
			t += (s[d] - '0');
			if (t > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (t);
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
	int k, c;
	unsigned int _abs_, curr;

	c = 0;
	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		c++;
	}
	else
		_abs_ = input;
	curr = _abs_;
	for (k = 1000000000; k > 1; k /= 10)
	{
		if (_abs_ / k)
		{
			__putchar('0' + curr / k);
			c++;
		}
		curr %= k;
	}
	__putchar('0' + curr);
	c++;
	return (c);
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
	int n;

	for (n = 0; buf[n] != '\0'; n++)
		if (buf[n] == '#' && (!n || buf[n - 1] == ' '))
		{
			buf[n] = '\0';
			break;
		}
}
