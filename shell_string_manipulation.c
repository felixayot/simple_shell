#include "main.h"
/**
 * _strlen - Function prototype
 * Destination: returns the length of a string
 * @s: char string
 * Return: string length
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
/**
 * _strcmp - Function prototype
 * Destination: performs lexicogarphic comparison of two strangs.
 * @str1: char string
 * @str2: char string
 * Return: o (Equal), - (str1 < str2), + (str1 > str2)
 */
int _strcmp(char *str1, char *str2)
{
while (*str1 && *str2)
{
if (*str1 != *str2)
return (*str1 - *str2);
str1++;
str2++;
}
if (*str1 == *str2)
return (0);
else
return (*str1 < *str2 ? -1 : 1);
}
/**
 * str_str - Function prototype
 * Description: locates a substring
 * @haystack: char string
 * @needle: char string
 * Return: haystack (pointer to the beginning of the located substring)
 * or NULL (substring is not found)
 */
char *str_str(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * _strcat - Function prototype
 * Destination: concatenates two strings
 * @new: char string
 * @str: char string
 * Return: new linked pointer
 */
char *_strcat(char *new, char *str)
{
char *ptr = new;
while (*new)
new++;
while (*str)
{
*new++ = *str++;
*new = *str;
}
return (ptr);
}
