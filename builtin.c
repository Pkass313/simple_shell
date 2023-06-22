#include "shell.h"

/**
 * _myexit - A function that exits the shell
 * @info: Structure containing potential arguments
 * Return: exits with a given exit status otherwise
 * return (0) if info.argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit;

	if (info->argv[1])
	{
		exit = _erratoi(info->argv[1]);
		if (exit == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}

/**
 * _mycd - A function that changes the current directory of the process
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _mycd(info_t *info)
{
	char *m, *ptr, buffer[1024];
	int chdir_ret;

	m = getcwd(buffer, 1024);
	if (!m)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!info->argv[1])
	{
		ptr = _getenv(info, "HOME=");
		if (!ptr)
			chdir_ret = chdir((ptr = _getenv(info, "PWD=")) ? ptr : "/");
		else
			chdir_ret = chdir(ptr);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(m);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_ret = chdir((ptr = _getenv(info, "OLDPWD=")) ? ptr : "/");
	}
	else
		chdir_ret = chdir(info->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - A funtion that changes the current directory of the process
 * @info: Structure containing potential arguments
 * Return: 0 (Success)
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
