#include "main.h"
/**
 * is_terminal - Function prototype
 * Description: Checks if shell is in interactive mode
 * @i: string pointer
 * Return: 1 (true) or 0 (false)
 */
int is_terminal(simpsh_t *i)
{
return (isatty(STDIN_FILENO) && i->inputsize <= 2);
}
/**
 * is_separator - Function prototype
 * Description: Checks if a char is a delimeter
 * @c: char
 * @separator: char string
 * Return: 1 (true) or 0 (false)
 */
int is_separator(char c, char *separator)
{
while (*separator)
if (*separator++ == c)
return (1);
return (0);
}
/**
 * _isalpha - Function prototype
 * Description: Checks for alphabetic character
 * @c: char
 * Return: 1 (true) 0 (false)
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
{
return (1);
}
else
{
return (0);
}
}
/**
 * _atoi - Function prototype
 * Description: Converts a string to an integer
 * @s: char string
 * Return: int value or 0 (Failure)
 */
int _atoi(char *s)
{
int i;
int cn = 1;
int fh = 0;
int fig;
unsigned int num = 0;
for (i = 0; s[i] != '\0' && fh != 2; i++)
{
if (s[i] == '-')
cn *= -1;
if (s[i] >= '0' && s[i] <= '9')
{
fh = 1;
num *= 10;
num += (s[i] - '0');
}
else if (fh == 1)
fh = 2;
}
if (cn == -1)
{
fig = -num;
}
else
{
fig = num;
}
return (fig);
}
