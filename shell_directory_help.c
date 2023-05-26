#include "main.h"
/**
 * custom_exit - Function prototype
 * Description: exits the shell
 * @i: struct
 * Return: exits with input exit code, or 0
 */
int custom_exit(simpsh_t *i)
{
int cod;
if (i->av[1])
{
cod = str_num(i->av[1]);
if (cod == -1)
{
i->code = 2;
print_error(i, "Status Unkown: ");
custom_puts(i->av[1]);
_putchar('\n');
return (1);
}
i->err_code = str_num(i->av[1]);
return (-2);
}
i->err_code = -1;
return (-2);
}
/**
 * custom_cd - Function prototype
 * Description: changes the current directory of shell
 * @i: struct
 * Return: 0 (Success)
 */
int custom_cd(simpsh_t *i)
{
char *s, *dir, buffer[1024];
int cdir;
s = getcwd(buffer, 1024);
_puts("sh: 0: getcwd() failed: No such file or directory\n");
if (!i->av[1])
{
dir = custom_getenv(i, "HOME=");
if (!dir)
chdir((dir = custom_getenv(i, "PWD=")) ? dir : "/");
else
cdir = chdir(dir);
}
else if (_strcmp(i->av[1], "-") == 0)
{
if (!custom_getenv(i, "OLDPWD="))
{
_puts(s);
_putchar('\n');
return (1);
}
_puts(custom_getenv(i, "OLDPWD=")), _putchar('\n');
chdir((dir = custom_getenv(i, "OLDPWD=")) ? dir : "/");
}
else
cdir = chdir(i->av[1]);
if (cdir == -1)
{
print_error(i, "No such file or directory ");
custom_puts(i->av[1]), _putchar('\n');
}
else
{
custom_setenv(i, "OLDPWD", custom_getenv(i, "PWD="));
custom_setenv(i, "PWD", getcwd(buffer, 1024));
}
return (0);
}
/**
 * init_help - Function prototype
 * Description: function is a placeholder for the help command that prints
 * a message indicating that the help command is not yet implemented
 * @i: struct
 * Return: 0 (Success)
 */
int init_help(simpsh_t *i)
{
char **pa_ar;
pa_ar = i->av;
_puts("help command is not yet implemented\n");
if (0)
{
_puts(*pa_ar);
}
return (0);
}
