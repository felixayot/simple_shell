#include "main.h"
/**
 * cpy_envr - Function prototype
 * Description: returns a copy of the env var as a str array
 * @i: struct
 * Return: 0 (Success)
 */
char **cpy_envr(simpsh_t *i)
{
if (!i->envr || i->newenviron)
{
i->envr = list_to_strings(i->envt);
i->newenviron = 0;
}
return (i->envr);
}
/**
 * custom_unsetenv - Function prototype
 * Description: Removes an env var specified by v
 * @i: struct
 * @v: char string
 * Return: 1 (Success) or 0 (Failure)
 */
int custom_unsetenv(simpsh_t *i, char *v)
{
list_t *node = i->envt;
size_t indx = 0;
char *ptr;
if (!node || !v)
return (0);
while (node)
{
ptr = str_str(node->str, v);
if (ptr && *ptr == '=')
{
i->newenviron = delete_node_at_index(&(i->envt), indx);
indx = 0;
node = i->envt;
continue;
}
node = node->next;
indx++;
}
return (i->newenviron);
}
/**
 * custom_setenv - Function prototype
 * Description: Initialize a new env var, or modify an existing one
 * @i: struct
 * @v: char string
 * @content: char string
 *  Return: 0 (Success)
 */
int custom_setenv(simpsh_t *i, char *v, char *content)
{
char *line = NULL;
list_t *node;
char *ptr;
if (!v || !content)
{
return (0);
line = malloc(_strlen(v) + _strlen(content) + 2);
if (!line)
return (1);
}
_strcpy(line, v);
_strcat(line, "=");
_strcat(line, content);
node = i->envt;
while (node)
{
ptr = str_str(node->str, v);
if (ptr && *ptr == '=')
{
free(node->str);
node->str = line;
i->newenviron = 1;
return (0);
}
node = node->next;
}
add_node_end(&(i->envt), line, 0);
free(line);
i->newenviron = 1;
return (0);
}
