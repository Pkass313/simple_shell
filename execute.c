#include "shell.h"

/**
* is_cmd - verifies if a file is an executable command
* @info: Structure of info
* @path: file path
*
* Return: 1 if success, 0 otherwise
*/

int is_cmd(info_t *info, char *path)

{
	struct stat st;
	(void)info;
	if (!path || stat(path, &st))
		return (0);
	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}

/**
* dup_chars - characters will duplicate
* @pathstr: PATH string
* @start: commencing index
* @stop: ending index
*
* Return: new buffer at pointer
*/

char *dup_chars(char *pathstr, int start, int stop)

{
	static char buf[1024];
	int o = 0, k = 0;

	for (k = 0, o = start; o < stop; o++)
		if (pathstr[o] != ':')
			buf[k++] = pathstr[o];

	buf[k] = 0;
	return (buf);

}

/**
* find_path - locates cmd in the PATH string
* @info: Structure of informatine
* @pathstr: PATH string
* @cmd: cmd to locate
*
* Return: entire path of cmd if found, otherwise 0
*/

char *find_path(info_t *info, char *pathstr, char *cmd)

{
	int o = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[o] || pathstr[o] == ':')
		{
			path = dup_chars(pathstr, curr_pos, o);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[o])
				break;
			curr_pos = o;
		}
		o++;
	}
	return (NULL);
}
