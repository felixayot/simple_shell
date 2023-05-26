#include "main.h"
/**
 * _memset - Function prototype
 * Description: fills memory with a constant byte
 * @s: char string
 * @b: char string
 * @n: int
 * Return: pointer
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
/**
 * free_str - Function prototype
 * Description: frees a string of strings
 * @str: string of strings
 */
void free_str(char **str)
{
char **a = str;
if (!str)
return;
while (*str)
free(*str++);
free(a);
}
/**
 * manual_realloc - Function prototype
 * Description: reallocates a block of memory
 * @ptr: pointer
 * @old_size: int
 * @new_size: int
 * Return: pointer to old mem block
 */
void *manual_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
{
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
}
return (p);
}
