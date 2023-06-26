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
	struct stat sm;
	(void)info;
	if (!path || stat(path, &sm))
		return (0);
	if (sm.st_mode & S_IFREG)
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
	int m = 0, h = 0;

	for (h = 0, m = start; m < stop; m++)
		if (pathstr[m] != ':')
			buf[h++] = pathstr[m];

	buf[h] = 0;
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
	int m = 0, curr_pos = 0;
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
		if (!pathstr[m] || pathstr[m] == ':')
		{
			path = dup_chars(pathstr, curr_pos, m);
			if (!*path)
				_strcat(path, cmd);
			else
			{
				_strcat(path, "/");
				_strcat(path, cmd);
			}
			if (is_cmd(info, path))
				return (path);
			if (!pathstr[m])
				break;
			curr_pos = m;
		}
		m++;
	}
	return (NULL);
}
