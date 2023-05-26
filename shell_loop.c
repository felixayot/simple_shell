#include "main.h"
/**
 * simple_shell - Function prototype
 * Description: program loop
 * @i: struct
 * @argv: argument vector
 * Return: 0 (Success), 1 (Failure), or error code
 */
int simple_shell(simpsh_t *i, char *argv[])
{
ssize_t r = 0;
int defcode = 0;
while (r != -1 && defcode != -2)
{
init_simpsh(i);
if (is_terminal(i))
_puts("$ ");
_putchar(BUFF_F);
r = line_only(i);
if (r != -1)
{
set_simpsh(i, argv);
defcode = find_default(i);
if (defcode == -1)
find_cmd(i);
}
else if (is_terminal(i))
_putchar('\n');
free_simpsh(i, 0);
}
mod_hist(i);
free_simpsh(i, 1);
if (!is_terminal(i) && i->code)
exit(i->code);
if (defcode == -2)
{
if (i->err_code == -1)
exit(i->code);
exit(i->err_code);
}
return (defcode);
}
/**
 * find_default - Function prototype
 * Description: finds a builtin command
 * @i: struct
 * Return: -1 (builtin not found), 0 (Success), 1 (Exe Failure),
 * 2 (builtin signals exit)
 */
int find_default(simpsh_t *i)
{
int a;
int defcode = -1;
default_funcs bltin[] = {
{"exit", custom_exit},
{"env", _printenv},
{"help", init_help},
{"history", hist_record},
{"setenv", init_setenv},
{"unsetenv", init_unsetenv},
{"cd", custom_cd},
{"alias", custom_alias},
{NULL, NULL}
};
for (a = 0; bltin[a].type; a++)
if (_strcmp(i->av[0], bltin[a].type) == 0)
{
i->input++;
defcode = bltin[a].func(i);
break;
}
return (defcode);
}
/**
 * find_cmd - Function prototype
 * Description: finds a command in PATH
 * @i: struct
 * Return: void
 */
void find_cmd(simpsh_t *i)
{
char *path = NULL;
int a, k;
i->pth = i->av[0];
if (i->buffsize_code == 1)
{
i->input++;
i->buffsize_code = 0;
}
for (a = 0, k = 0; i->ag[a]; a++)
if (!is_separator(i->ag[a], " \t\n"))
k++;
if (!k)
return;
path = find_path(i, custom_getenv(i, "PATH="), i->av[0]);
if (path)
{
i->pth = path;
_fork(i);
}
else
{
if ((is_terminal(i) || custom_getenv(i, "PATH=")
|| i->av[0][0] == '/') && is_exe(i->av[0]))
_fork(i);
else if (*(i->ag) != '\n')
{
i->code = 127;
print_error(i, "not found\n");
}
}
}
/**
 * _fork - Function prototype
 * Description: forks child process to execute cmd
 * @i: struct
 * Return: void
 */
void _fork(simpsh_t *i)
{
pid_t pid;
pid = fork();
if (pid == -1)
{
perror("Error: Fork Failed");
}
if (pid == 0)
{
if (execve(i->pth, i->av, cpy_envr(i)) == -1)
{
free_simpsh(i, 1);
if (errno == EACCES)
exit(126);
exit(1);
}
}
else
{
wait(&(i->code));
}
if (WIFEXITED(i->code))
{
i->code = WEXITSTATUS(i->code);
if (i->code == 126)
print_error(i, "Permission denied\n");
}
}
