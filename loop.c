#include "main.h"
/**
*hsh - main shell loop
*@info: the parameter & return info struct
*@av: argument vector
*Return: 0 on success 1 on failure
*/
int hsh(info_t *info, char **av)
{
	ssize_t v = 0;
	int builtin_ret = 0;

	while (v != -1 && builtin_ret != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar(BUF_FLUSH);
		v = get_input(info);
		if (v != -1)
		{
			set_info(info, av);
			builtin_ret = find_builtin(info);
			if (builtin_ret == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_ret == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_ret);
}

/**
*find_builtin - finds a builtin command
*@info: the parameter
*Return: -1 if builtin not found 0 if successfully found
*/
int find_builtin(info_t *info)
{
	int v, built_in_ret = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL},
	};
	if (info == NULL || info->argv == NULL || info->argv == NULL)
	{
		return (-1);
	}

	for (v = 0; builtintbl[v].type; v++)
	{
		if (_strcmp(info->argv[0], builtintbl[v].type) == 0)
		{
			info->line_count++;
			built_in_ret = builtintbl[v].func(info);
			break;
		}
	}
	return (built_in_ret);
}

/**
*find_cmd - looks for a command in path
*@info: the parameter
*Return: nothing
*/
void find_cmd(info_t *info)
{
	char *path = NULL;
	int u, p;

	if (info == NULL || info->argv == NULL || info->arg == NULL)
	{
		return;
	}
	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (u = 0, p = 0; info->arg[u]; u++)
	{
		if (!is_delim(info->arg[u], " \t\n"))
		{
			p++;
		}
		if (!p)
			return;
		path = findPath(info, _getenv(info, "PATH="), info->argv[0]);
		if (path)
		{
			info->path = path;
			fork_cmd(info);
		}
		else
		{
			if ((interactive(info) || _getenv(info, "PATH=")
						|| info->argv[0][0] == '/') && isCmd(info, info->argv[0]))
			fork_cmd(info);
			else if (*(info->arg) != '\n')
			{
				info->status = 127;
				print_error(info, "not found\n");
			}
		}
	}
}

/**
*forkCmd - forks a thread to run a command
*@info: parameter
*Return: void
*/
void fork_cmd(info_t *info)
{
	pid_t child_pid;
	
	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
