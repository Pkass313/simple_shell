#include "shell.h"

/**
 * input_buf - A function that buffers chained commands
 * @info: The parameter struct
 * @buf: The address of buffer
 * @len: The address of len var
 * Return: The bytes
 */
ssize_t input_buf(info_t *info, char **buf, size_t *len)
{
	size_t y;
	size_t len_m = 0;

	y = 0;
	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		y = getline(buf, &len_m, stdin);
#else
		y = _getline(info, buf, &len_m);
#endif
		if (y > 0)
		{
			if ((*buf)[y - 1] == '\n')
			{
				(*buf)[y - 1] = '\0';
				y--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = y;
				info->cmd_buf = buf;
			}
		}
	}
	return (y);
}

/**
 * get_input - A function that gets a line minus the newline
 * @info: The parameter struct
 * Return: The bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t o, z, len;
	ssize_t y;
	char **buf_m = &(info->arg), *m;

	y = 0;
	_putchar(BUF_FLUSH);
	y = input_buf(info, &buf, &len);
	if (y == -1)
		return (-1);
	if (len)
	{
		z = o;
		m = buf + o;
		check_chain(info, buf, &z, o, len);
		while (z < len)
		{
			if (is_chain(info, buf, &z))
				break;
			z++;
		}
		o = z + 1;
		if (o >= len)
		{
			o = len = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_m = m;
		return (_strlen(m));
	}

	*buf_m = buf;
	return (y);
}

/**
 * read_buf - A function that reads a buffer
 * @info: The parameter struct
 * @buf: A buffer
 * @i: The size
 * Return:p
 */
ssize_t read_buf(info_t *info, char *buf, size_t *i)
{
	ssize_t m;

	m = 0;
	if (*i)
		return (0);
	m = read(info->readfd, buf, READ_BUF_SIZE);
	if (m >= 0)
		*i = m;
	return (m);
}

/**
 * _getline - A function that gets the next line of input from STDIN
 * @info: The parameter struct
 * @opt: The address of the pointer to buffer
 * @length: The size of preallocated ptr buffer if not NULL
 * Return: t
 */
int _getline(info_t *info, char **opt, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t o, len;
	size_t x;
	ssize_t y = 0, t = 0;
	char *m = NULL, *new_m = NULL, *d;

	m = *opt;
	if (m && length)
		t = *length;
	if (o == len)
		o = len = 0;
	y = read_buf(info, buf, &len);
	if (y == -1 || (y == 0 && len == 0))
		return (-1);
	d = _strchr(buf + o, '\n');
	x = d ? 1 + (unsigned int)(d - buf) : len;
	new_m = _realloc(m, t, t ? t + x : x + 1);
	if (!new_m)
		return (m ? free(m), -1 : -1);
	if (t)
		_strncat(new_m, buf + o, x - o);
	else
		_strncpy(new_m, buf + o, x - o + 1);
	t += x - o;
	o = x;
	m = new_m;
	if (length)
		*length = t;
	*opt = m;
	return (t);
}

/**
 * sigintHandler - A function that blocks ctrl-C
 * @sig_num: The signal number
 * Return: void
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("$");
	_putchar(BUF_FLUSH);
}
