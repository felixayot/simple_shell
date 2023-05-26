#include "main.h"
/**
 * _strcpy - Function prototype
 * Destination: copies a string
 * @new: char string
 * @str: char string
 * Return: new char string
 */
char *_strcpy(char *new, char *str)
{
int i = 0;
if (new == str || str == 0)
return (new);
while (str[i])
{
new[i] = str[i];
i++;
}
new[i] = 0;
return (new);
}
/**
 * _strdup - Function prototype
 * Description: duplicates a string
 * @str: char string
 * Return: duplicated char *string
 */
char *_strdup(const char *str)
{
int len = 0;
char *str2;
if (str == NULL)
return (NULL);
while (*str++)
len++;
str2 = malloc(sizeof(char) * (len + 1));
if (!str2)
return (NULL);
for (len++; len--;)
str2[len] = *--str;
free(str2);
return (str2);
}
/**
 * _puts - prints an input string
 * @str: the string to be printed
 * Return: Nothing
 */
void _puts(char *str)
{
int i = 0;
if (!str)
{
return;
}
while (str[i] != '\0')
{
_putchar(str[i]);
i++;
}
}
