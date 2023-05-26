#include "main.h"
/**
 * hist_record - Function prototype
 * Description: displays history record, one cmd by line, preceded
 * with line numbers, starting at 0.
 * @i: struct
 * Return: 0 (Success)
 */
int hist_record(simpsh_t *i)
{
print_list(i->hist);
return (0);
}
/**
 * release_alias - Function prototype
 * Description: releases alias to string
 * @i: struct
 * @str: string char
 * Return: Always 0 (Success), 1 (Failure)
 */
int release_alias(simpsh_t *i, char *str)
{
char *p, c;
int set;
p = _strchr(str, '=');
if (!p)
return (1);
c = *p;
*p = 0;
set = delete_node_at_index(&(i->alias),
get_node_index(i->alias, node_prefix(i->alias, str, -1)));
*p = c;
return (set);
}

/**
 * set_alias - Function prototype
 * Description: sets alias to string
 * @i: struct
 * @str: string alias
 * Return: 0 (Success), 1 (Failure)
 */
int set_alias(simpsh_t *i, char *str)
{
char *p;
p = _strchr(str, '=');
if (!p)
return (1);
if (!*++p)
return (release_alias(i, str));
release_alias(i, str);
return (add_node_end(&(i->alias), str, 0) == NULL);
}
/**
 * print_alias - Function prototype
 * Description: prints an alias string
 * @node: struct
 * Return: 0 on (Success), 1 on error
 */
int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;
if (node)
{
p = _strchr(node->str, '=');
for (a = node->str; a <= p; a++)
_putchar(*a);
_putchar('\'');
_puts(p + 1);
_puts("'\n");
return (0);
}
return (1);
}
/**
 * custom_alias - Function prototype
 * Description: displays aliases
 * @i: struct
 * Return: 0 (Success)
 */
int custom_alias(simpsh_t *i)
{
int a = 0;
char *p = NULL;
list_t *node = NULL;
if (i->ac == 1)
{
node = i->alias;
while (node)
{
print_alias(node);
node = node->next;
}
return (0);
}
for (a = 1; i->av[a]; a++)
{
p = _strchr(i->av[a], '=');
if (p)
{
set_alias(i, i->av[a]);
}
else
{
print_alias(node_prefix(i->alias, i->av[a], '='));
}
}
return (0);
}
