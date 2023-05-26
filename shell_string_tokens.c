#include "main.h"
/**
 * strtow - Function prototype
 * Destination: separates a string into words while ignoring repeat separators
 * @str: char string
 * @sp: char string
 * Return: string pointer or NULL (Failure)
 */
char **strtow(char *str, char *sp)
{
int a, b, c, d;
int wc = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
if (!sp)
sp = " ";
for (a = 0; str[a] != '\0'; a++)
if (!is_separator(str[a], sp) && (is_separator(str[a + 1], sp) || !str[a + 1]))
wc++;
if (wc == 0)
return (NULL);
s = malloc((1 + wc)*sizeof(char *));
if (!s)
return (NULL);
for (a = 0, b = 0; b < wc; b++)
{
while (is_separator(str[a], sp))
a++;
c = 0;
while (!is_separator(str[a + c], sp) && str[a + c])
c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s);
return (NULL);
}
for (d = 0; d < c; d++)
s[b][d] = str[a++];
s[b][d] = 0;
}
s[b] = NULL;
return (s);
}
/**
 * custom_strtow - Function prototype
 * Destination: splits a string into words
 * @str: char string
 * @sp: char
 * Return: pointer string or NULL (Failure)
 */
char **custom_strtow(char *str, char sp)
{
int a, b, c, d;
int wc = 0;
char **s;
if (str == NULL || str[0] == 0)
return (NULL);
for (a = 0; str[a] != '\0'; a++)
if ((str[a] != sp && str[a + 1] == sp) ||
(str[a] != sp && !str[a + 1]) || str[a + 1] == sp)
wc++;
if (wc == 0)
{
return (NULL);
}
s = malloc((1 + wc)*sizeof(char *));
if (!s)
return (NULL);
for (a = 0, b = 0; b < wc; b++)
{
while (str[a] == sp && str[a] != sp)
a++;
c = 0;
while (str[a + c] != sp && str[a + c] && str[a + c] != sp)
c++;
s[b] = malloc((c + 1) * sizeof(char));
if (!s[b])
{
for (c = 0; c < b; c++)
free(s[c]);
free(s);
return (NULL);
}
}
for (d = 0; d < c; d++)
{
s[b][d] = str[a++];
s[b][d] = 0;
}
s[b] = NULL;
return (s);
}
