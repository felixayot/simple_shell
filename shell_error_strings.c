#include "main.h"
/**
 * custom_puts - prints an input string
 * @str: char string
 * Return: void
 */
void custom_puts(char *str)
{
int i = 0;
if (!str)
return;
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}
/**
 * _putchar - Function prototype
 * Description: writes the character c to stdout
 * @c: char
 * Return: 1 (Success) or -1 (Failure)
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
/**
 * custom_putcfd - Function prototype
 * Description: writes the character c to a specified file descriptor
 * @c: char
 * @fd: int
 * Return: 1 (Success) or -1 (Failure).
 */
int custom_putcfd(char c, int fd)
{
static int a;
static char b[WRITE_BUFFSIZE];
if (c == BUFF_F || a >= WRITE_BUFFSIZE)
{
write(fd, b, a);
a = 0;
}
if (c != BUFF_F)
b[a++] = c;
return (1);
}
/**
 * custom_putsfd - Function prototype
 * Description: prints an input string
 * @str: char string
 * @fd: int
 * Return: the number of chars put
 */
int custom_putsfd(char *str, int fd)
{
int i = 0;
if (!str)
{
return (0);
}
while (*str)
{
i += custom_putcfd(*str++, fd);
}
return (i);
}
