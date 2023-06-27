#include "shell.h"

/**
* _eputs - input string will print
* @str: string that will print
* Return: Null
*/

void _eputs(char *str)

{
	int o = 0;

	if (!str)

		return;
	while (str[o] != '\0')
	{
		_eputchar(str[o]);
		o++;
	}
}

/**
* _eputchar - will write p char to stderr
* @d: Char to print
* Return: On success 1
* On error, -1 is returned, errno appropriately set
*/

int _eputchar(char d)

{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || o >= WRITE_BUF_SIZE)

	{
		write(2, buf, o);
		o = 0;
	}

	if (d != BUF_FLUSH)

		buf[o++] = d;

	return (1);
}

/**
* _putfd - will write p char to given fd
* @d: Char to print
* @fd:Filedescriptor to write to
* Return: On success 1.
* On error, -1 is returned, and errno appropriately set
*/

int _putfd(char d, int fd)

{
	static int o;
	static char buf[WRITE_BUF_SIZE];

	if (d == BUF_FLUSH || o >= WRITE_BUF_SIZE)

	{
		write(fd, buf, o);
		o = 0;
	}

	if (d != BUF_FLUSH)

		buf[o++] = d;

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
	int o = 0;

	if (!str)

		return (0);

	while (*str)
	{
		o += _putfd(*str++, fd);
	}

	return (o);
}
