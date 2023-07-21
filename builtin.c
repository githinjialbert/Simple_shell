#include "main.h"
/**
*_myexit - exits the shell program
*@info: all potential arguments
*Return: exits with a given status
*/
int _myexit(info_t *info)
{
	int exitnow;

	if (info->argv[1])
	{
		exitnow = _erratoi(info->argv[1]);
		if (exitnow == -1)
		{
			info->status = 2;
			print_error(info, "Ilegal number: ");
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
*_mycd - changes the current working directory
*@info: contains potential arguments
*Return: always 0
*/
int _mycd(info_t *info)
{
	char *d, *dir, buffer[1024];
	int chdir_m;

	d = getcwd(buffer, 1024);
	if (!d)
		_puts("TODO: >>getcwd failure esmg here<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			chdir_m = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(d);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		chdir_m = chdir(info->argv[1]);
		if (chdir_m == -1)
		{
			print_error(info, "cant cd to");
			_eputs(info->argv[1]), _eputchar('\n');
		}
		else
		{
			_setenv(info, "OLDPWD", _getenv(info, "PWD="));
			_setenv(info, "PWD", getcwd(buffer, 1024));
		}
	}
	return (0);
}

/**
*_myhelp - changes the process
*@info: contains potential arguments
*Return: void
*/
int _myhelp(info_t *info)
{
	char **argArr;

	argArr = info->argv;
	_puts("help call works. Function not implemented\n");
	if (0)
	{
		_puts(*argArr);
	}
	return (0);
}
