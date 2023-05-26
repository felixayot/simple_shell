#include "main.h"
/**
 * str_num - Function prototype
 * Description: converts a string to an integer
 * @s: char string
 * Return: converted int, 0 or -1 (Failure)
 */
int str_num(char *s)
{
int i = 0;
unsigned long int l = 0;
if (*s == '+')
s++;
for (i = 0;  s[i] != '\0'; i++)
{
if (s[i] >= '0' && s[i] <= '9')
{
l *= 10;
l += (s[i] - '0');
if (l > MAX_RECORD)
return (-1);
}
else
return (-1);
}
return (l);
}
/**
 * print_error - Function prototype
 * Description: prints an error message
 * @i: struct
 * @str: char string
 * Return: void
 */
void print_error(simpsh_t *i, char *str)
{
custom_puts(i->file_name);
custom_puts(": ");
print_float(i->input, STDERR_FILENO);
custom_puts(": ");
custom_puts(i->av[0]);
custom_puts(": ");
custom_puts(str);
}

/**
 * print_float - Function prototype
 * Description: prints a floating point int
 * @input: int
 * @fd: int
 * Return: number of characters printed
 */
int print_float(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i;
int num = 0;
unsigned int _abs_, current;
if (fd == STDERR_FILENO)
__putchar = _putchar;
if (input < 0)
{
_abs_ = -input;
__putchar('-');
num++;
}
else
_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
if (_abs_ / i)
{
__putchar('0' + current / i);
num++;
}
current %= i;
}
__putchar('0' + current);
num++;
return (num);
}
/**
 * num_str - Function prototype
 * Description: converts number to string
 * @num: int
 * @base: int
 * @flags: int
 * Return: resulting string
 */
char *num_str(long int num, int base, int flags)
{
static char *a;
static char b[50];
char c = 0;
char *ptr;
unsigned long l = num;
if (!(flags & UNSIGN_CONV) && num < 0)
{
l = -num;
c = '-';
}
a = flags & LWCASE_CONV ? "0123456789abcdef" : "0123456789ABCDEF";
ptr = &b[49];
*ptr = '\0';
do	{
*--ptr = a[l % base];
l /= base;
} while (l != 0);
if (c)
*--ptr = c;
return (ptr);
}
/**
 * de_comments - Function prototype
 * Description: replaces first instance of '#' with '\0'
 * @line: string char
 * Return: 0 (Success);
 */
void de_comments(char *line)
{
int indx;
for (indx = 0; line[indx] != '\0'; indx++)
{
if (line[indx] == '#' && (!indx || line[indx - 1] == ' '))
{
line[indx] = '\0';
break;
}
}
}
