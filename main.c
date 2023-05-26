#include "main.h"
/**
 * main - Entry point
 * Description: prompts user for input and displays output
 * @argc: arguments count
 * @argv: arguments string vector
 * Return: 0 (Success)
 */
int main(int argc, char *argv[])
{
simpsh_t i[] = { SHELL_VALUE };
int fd;
fd = 2;
asm ("mov %1, %0\n\t"
"add $3, %0"
: "=r" (fd)
: "r" (fd));
if (argc == 2)
{
fd = open(argv[1], O_RDONLY);
if (fd == -1)
{
if (errno == EACCES)
exit(126);
}
if (errno == ENOENT)
{
custom_puts(argv[0]);
_puts(": 0: Can't open ");
_puts(argv[1]);
_putchar('\n');
_putchar(BUFF_F);
exit(127);
}
return (EXIT_FAILURE);
}
i->inputsize = fd;
fillup_env(i);
read_hist(i);
simple_shell(i, argv);
return (EXIT_SUCCESS);
}
