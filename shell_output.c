#include "shell.h"

/**
* get_history_file - collects file history
* @info:Struct of parameter
* Return: string containing file history
*/

char *get_history_file(info_t *info)
{
	char *buf, *dir;

	dir = _getenv(info, "HOME=");
	if (!dir)

		return (NULL);

	buf = malloc(sizeof(char) * (_strlen(dir) + _strlen(HIST_FILE) + 2));
	if (!buf)
		return (NULL);
	buf[0] = 0;
	_strcpy(buf, dir);
	_strcat(buf, "/");
	_strcat(buf, HIST_FILE);

	return (buf);
}

/**
* write_history - will create file or adds to an existing file
* @info: Struct of parameters
* Return: 1 on success, else -1
*/

int write_history(info_t *info)

{
	ssize_t fd;
	char *filename = get_history_file(info);

	list_t *node = NULL;

	if (!filename)

		return (-1);
	fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(filename);
	if (fd == -1)
		return (-1);

	for (node = info->history; node; node = node->next)

	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);

	return (1);
}

/**
* read_history - will read  history from file
* @info: struct of parameters
* Return: history count on success, 0 otherwise
*/

int read_history(info_t *info)

{
	int o, last = 0, linecount = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buf = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);
	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buf = malloc(sizeof(char) * (fsize + 1));
	if (!buf)
		return (0);
	rdlen = read(fd, buf, fsize);
	buf[fsize] = 0;
	if (rdlen <= 0)
		return (free(buf), 0);
	close(fd);
	for (o = 0; o < fsize; o++)
		if (buf[o] == '\n')
		{
			buf[o] = 0;
			build_history_list(info, buf + last, linecount++);
			last = o + 1;
		}
	if (last != o)
		build_history_list(info, buf + last, linecount++);
	free(buf);
	info->histcount = linecount;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
* build_history_list - enters history to linked list
* @info: Struct of potential arguments
* @buf: buffer func
* @linecount: history of linecount and histcount
* Return: Always 0
*/

int build_history_list(info_t *info, char *buf, int linecount)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;

	add_node_end(&node, buf, linecount);

	if (!info->history)
		info->history = node;

	return (0);
}

/**
 * renumber_history - history linked list to renumber
 * @info: Struct of potential arguments
 * Return: the new histcount
 */

int renumber_history(info_t *info)

{
list_t *node = info->history;
	int o = 0;

	while (node)

	{
		node->num = o++;

		node = node->next;
	}
	return (info->histcount = o);
}
