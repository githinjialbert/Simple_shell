#include "main.h"
/**
*isCmd - determines if a file is executable
*@info: parameter
*@path: file path
*Return: 0 if unsuccessful 1 if successful
*/
int isCmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (-1);
	}
	return (0);
}

/**
*dupChars - it duplicates chars
*@pathstr: string path
*@start: starting point
*@stop: stopping point
*Return: a pointer
*/
char *dupChars(char *pathstr, int start, int stop)
{
	static char buf[1024];
	int u, p = 0;

	for (p = 0, u = start; u < stop; u++)
		if (pathstr[u] != ':')
			buf[p++] = pathstr[u];
	buf[p] = 0;
	return (buf);
}

/**
*findPath - finds the string path
*@info: parameter
*@pathstr: string path
*@cmd: the command to find
*Return: always 0
*/
char *findPath(info_t *info, char *pathstr, char *cmd)
{
	int v = 0, curr_pos = 0;
	char *path;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (isCmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[v] || pathstr[v] == ':')
		{
			path = dupChars(pathstr, curr_pos, v);
			if (!*path)
			{
				_strcat(path, cmd);
			}
				else
				{
					_strcat(path, "/");
					_strcat(path, cmd);
				}
				if (isCmd(info, path))
					return (path);
				if (!pathstr[v])
					break;
				curr_pos = v;
		}
		v++;
	}
	return (NULL);
}
