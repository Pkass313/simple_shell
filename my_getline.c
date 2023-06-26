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
	size_t z;
	size_t h = 0;

	z = 0;
	if (!*len)
	{
		free(*buf);
		*buf = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		z = getline(buf, &h, stdin);
#else
		z = _getline(info, buf, &h);
#endif
		if (z > 0)
		{
			if ((*buf)[z - 1] == '\n')
			{
				(*buf)[z - 1] = '\0';
				z--;
			}
			info->linecount_flag = 1;
			remove_comments(*buf);
			build_history_list(info, *buf, info->histcount++);
			{
				*len = z;
				info->cmd_buf = buf;
			}
		}
	}
	return (z);
}

/**
 * get_input - A function that gets a line minus the newline
 * @info: The parameter struct
 * Return: The bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf;
	static size_t o, t, l;
	ssize_t b;
	char **buf_y = &(info->arg), *y;

	b = 0;
	_putchar(BUF_FLUSH);
	b = input_buf(info, &buf, &l);
	if (b == -1)
		return (-1);
	if (l)
	{
		t = o;
		y = buf + o;
		check_chain(info, buf, &t, o, l);
		while (t < l)
		{
			if (is_chain(info, buf, &t))
				break;
			t++;
		}
		o = t + 1;
		if (o >= l)
		{
			o = l = 0;
			info->cmd_buf_type = CMD_NORM;
		}
		*buf_y = y;
		return (_strlen(y));
	}
	*buf_y = buf;
	return (b);
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
	ssize_t p;

	p = 0;
	if (*i)
		return (0);
	p = read(info->readfd, buf, READ_BUF_SIZE);
	if (p >= 0)
		*i = p;
	return (p);
}

/**
 * _getline - A function that gets the next line of input from STDIN
 * @info: The parameter struct
 * @opt: The address of the pointer to buffer
 * @len: The size of preallocated ptr buffer if not NULL
 * Return: t
 */
int _getline(info_t *info, char **opt, size_t *len)
{
	static char buf[READ_BUF_SIZE];
	static size_t o, l;
	size_t m;
	ssize_t r = 0, t = 0;
	char *x = NULL, *new_x = NULL, *u;

	x = *opt;
	if (x && len)
		t = *len;
	if (o == l)
		o = l = 0;
	r = read_buf(info, buf, &l);
	if (r == -1 || (r == 0 && l == 0))
		return (-1);
	u = _strchr(buf + o, '\n');
	m = u ? 1 + (unsigned int)(u - buf) : l;
	new_x = _realloc(x, t, t ? t + m : m + 1);
	if (!new_x)
		return (x ? free(x), -1 : -1);
	if (t)
		_strncat(new_x, buf + o, m - o);
	else
		_strncpy(new_x, buf + o, m - o + 1);
	t += m - o;
	o = m;
	x = new_x;
	if (len)
		*len = t;
	*opt = x;
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
