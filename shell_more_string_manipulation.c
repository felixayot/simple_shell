#include "main.h"
/**
 * _strncpy - Function prototype
 * Description: copies a string
 * @new: char string
 * @str: char string
 * @n: int
 * Return: the concatenated string
 */
char *_strncpy(char *new, char *str, int n)
{
int i;
int j;
char *s = new;
i = 0;
while (str[i] != '\0' && i < n - 1)
{
new[i] = str[i];
i++;
}
if (i < n)
{
j = i;
while (j < n)
{
new[j] = '\0';
j++;
}
}
return (s);
}
/**
 * _strncat - Function prototype
 * Description: concatenates two strings
 * @new: char string
 * @str: char string
 * @n: int
 * Return: the linked string
 */
char *_strncat(char *new, char *str, int n)
{
int i;
int j;
char *s = new;
i = 0;
j = 0;
while (new[i] != '\0')
i++;
while (str[j] != '\0' && j < n)
{
new[i] = str[j];
i++;
j++;
}
if (j < n)
new[i] = '\0';
return (s);
}
/**
 * _strchr - Function prototype
 * Description: locates a char in a string
 * @s: char string
 * @c: char
 * Return: char
 */
char *_strchr(char *s, char c)
{
do {
if (*s == c)
{
return (s);
} while (*s++ != '\0');
return (NULL);
}
