#include "main.h"
/**
 * _printenv - Function prototype
 * Description: prints environment variables
 * @i: int
 * Return: 0 (Success)
 */
int _printenv(simpsh_t *i)
{
print_list_str(i->envt);
return (0);
}
/**
 * custom_getenv - Function prototype
 * Description: gets the value of an env var
 * @i: struct
 * @name: char string
 * Return: the value
 */
char *custom_getenv(simpsh_t *i, const char *name)
{
list_t *node = i->envt;
char *ptr;
while (node)
{
ptr = str_str(node->str, name);
if (ptr && *ptr)
return (ptr);
node = node->next;
}
return (NULL);
}
/**
 * init_setenv - Function prototype
 * Description: initializes a new envt var, or modify an existing one
 * @i: struct
 * Return: 0 (Success)
 */
int init_setenv(simpsh_t *i)
{
if (i->ac != 3)
{
custom_puts("Invalid arguments count\n");
return (1);
}
if (custom_setenv(i, i->av[1], i->av[2]))
return (0);
return (1);
}
/**
 * init_unsetenv - Function prototype
 * Description: Remove an environment variable
 * @i: struct
 * Return: 0 (Success)
 */
int init_unsetenv(simpsh_t *i)
{
int indx;
if (i->ac == 1)
{
custom_puts("Too few arguments\n");
return (1);
}
for (indx = 1; indx <= i->ac; indx++)
custom_unsetenv(i, i->av[indx]);
return (0);
}

/**
 * fillup_env - Function prototype
 * Description: fills up envt
 * @i: struct
 * Return: Always 0
 */
int fillup_env(simpsh_t *i)
{
list_t *node = NULL;
size_t indx;
for (indx = 0; environ[indx]; indx++)
add_node_end(&node, environ[indx], 0);
i->envt = node;
return (0);
}
