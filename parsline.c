#include "main.h"
/**
*is_cmd - determines if a file is executable
*@info: parameter
*@path: file path
*Return: 0 if unsuccessful 1 if successful
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
*dup_chars - it duplicates chars
*@pathstr: string path
*@start: starting point
*@stop: stopping point
*Return: a pointer
*/
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int i = 0, k = 0;

	for (k = 0, i = start; i < stop; i++)
		if (pathstr[i] != ':')
			buf[k++] = pathstr[i];
	buf[k] = 0;
	return (buf);
}

/**
*find_path - finds the string path
*@info: parameter
*@pathstr: string path
*@cmd: the command to find
*Return: always 0
*/
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int i = 0, curr_pos = 0;
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
		if (!pathstr[i] || pathstr[i] == ':')
		{
			path = dup_chars(pathstr, curr_pos, i);
			if (!*path)
			{
				_strcat(path, cmd);
			}
				else
				{
					_strcat(path, "/");
					_strcat(path, cmd);
				}
				if (is_cmd(info, path))
					return (path);
				if (!pathstr[i])
					break;
				curr_pos = i;
		}
		i++;
	}
	return (NULL);
}
