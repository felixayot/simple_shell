#include "main.h"
/**
 * is_exe - Function prototype
 * Description: determines if a file is an executable command
 * @path: char string
 * Return: 1 (True), 0 (False)
 */
int is_exe(char *path)
{
struct stat st;
if (!path || stat(path, &st))
return (0);
if (st.st_mode & S_IFREG)
{
return (1);
}
return (0);
}
/**
 * chars_cpy - Function prototype
 * Description: duplicates characters
 * @pathstr: char string
 * @start: int
 * @stop: int
 * Return: new char
 */
char *chars_cpy(char *pathstr, int start, int stop)
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
 * find_path - Function prototype
 * Description: finds this cmd in the PATH string
 * @i: struct
 * @pathstr: string char
 * @cmd: string char
 * Return: full path of cmd or NULL (Failure)
 */
char *find_path(simpsh_t *i, char *pathstr, char *cmd)
{
int a = 0, curr_pos = 0;
char *path;
(void) i;
if (!pathstr)
return (NULL);
if ((_strlen(cmd) > 2) && str_str(cmd, "./"))
{
if (is_exe(cmd))
return (cmd);
}
while (1)
{
if (!pathstr[a] || pathstr[a] == ':')
{
path = chars_cpy(pathstr, curr_pos, a);
if (!*path)
{
_strcat(path, cmd);
}
else
{
_strcat(path, "/");
_strcat(path, cmd);
}
if (is_exe(path))
return (path);
}
if (!pathstr[a])
{
break;
curr_pos = a;
}
a++;
}
return (NULL);
}
