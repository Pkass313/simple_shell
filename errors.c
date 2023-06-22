#include "shell.h"

/**
* _eputs - input string will print
* @str: string that will print
* Return: Null
*/

void _eputs(char *str)

{
	int m = 0;

	if (!str)

		return;
	while (str[m] != '\0')
	{
		_eputchar(str[m]);
		m++;
	}
}

/**
* _eputchar - will write p char to stderr
* @c: Char to print
* Return: On success 1
* On error, -1 is returned, errno appropriately set
*/

int _eputchar(char c)

{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)

	{
		write(2, buf, m);
		m = 0;
	}

	if (c != BUF_FLUSH)

		buf[m++] = c;

	return (1);
}

/**
* _putfd - will write p char to given fd
* @c: Char to print
* @fd:Filedescriptor to write to
* Return: On success 1.
* On error, -1 is returned, and errno appropriately set
*/

int _putfd(char c, int fd)

{
	static int m;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || m >= WRITE_BUF_SIZE)

	{
		write(fd, buf, m);
		m = 0;
	}

	if (c != BUF_FLUSH)

		buf[m++] = c;

	return (1);
}

/**
* _putsfd - prints an input string to given fd
* @str: String to print
* @fd: Filedescriptor to write to
* Return: Num of chars put
*/

int _putsfd(char *str, int fd)

{
	int m = 0;

	if (!str)

		return (0);

	while (*str)
	{
		m += _putfd(*str++, fd);
	}

	return (m);
}
