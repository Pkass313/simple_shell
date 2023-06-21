#include "shell.h"

/**
* _eputs - input string will print
* @str: string that will print
* Return: Null
*/

void _eputs(char *str)

{
	int i = 0;

	if (!str)

		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
* _eputchar - will write p char to stderr
* @p: Char to print
* Return: On success 1
* On error, -1 is returned, errno appropriately set
*/

int _eputchar(char p)

{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (p == BUF_FLUSH || i >= WRITE_BUF_SIZE)

	{
		write(2, buf, i);
		i = 0;
	}

	if (p != BUF_FLUSH)

		buf[i++] = p;

	return (1);
}

/**
* _putfd - will write p char to given fd
* @p: Char to print
* @fd:Filedescriptor to write to
* Return: On success 1.
* On error, -1 is returned, and errno appropriately set
*/

int _putfd(char p, int fd)

{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (p == BUF_FLUSH || i >= WRITE_BUF_SIZE)

	{
		write(fd, buf, i);
		i = 0;
	}

	if (p != BUF_FLUSH)

		buf[i++] = p;

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
	int i = 0;

	if (!str)

		return (0);

	while (*str)
	{
		i += _putfd(*str++, fd);
	}

	return (i);
}
