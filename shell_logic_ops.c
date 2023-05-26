#include "main.h"
/**
 * is_logical_operator - Function prototype
 * Description: checks if current char in buffer is a commands
 * separator ;, OR, AND
 * @i: struct
 * @line: char string
 * @p: int
 * Return: 1 (cmd separator), 0 otherwise
 */
int is_logical_operator(simpsh_t *i, char *line, size_t *p)
{
size_t b = *p;
if (line[b] == '|' && line[b + 1] == '|')
{
line[b] = 0;
b++;
i->cmdtype = OR_CMD;
}
else if (line[b] == '&' && line[b + 1] == '&')
{
line[b] = 0;
b++;
i->cmdtype = AND_CMD;
}
else if (line[b] == ';')
{
line[b] = 0;
i->cmdtype = CHAIN_CMD;
}
else
return (0);
*p = b;
return (1);
}
/**
 * continue_chain - Function prototype
 * Description: checks for a possible chaining based on last status
 * @i: struct
 * @buff: string char
 * @p: int
 * @a: int
 * @len: int
 * Return: Void
 */
void continue_chain(simpsh_t *i, char *buff, size_t *p, size_t a, size_t len)
{
size_t b = *p;
if (i->cmdtype == AND_CMD)
{
if (i->code)
{
buff[a] = 0;
b = len;
}
}
if (i->cmdtype == OR_CMD)
{
if (!i->code)
{
buff[a] = 0;
b = len;
}
}
*p = b;
}
/**
 * replace_alias - Function prototype
 * Description: replaces aliases in the tokenized string
 * @i: struct
 * Return: 1 (Success), 0 otherwise
 */
int replace_alias(simpsh_t *i)
{
int a;
list_t *node;
char *p;
for (a = 0; a < 10; a++)
{
node = node_prefix(i->alias, i->av[0], '=');
if (!node)
return (0);
free(i->av[0]);
p = _strchr(node->str, '=');
if (!p)
return (0);
p = _strdup(p + 1);
if (!p)
return (0);
i->av[0] = p;
}
return (1);
}
/**
 * replace_variables - Function prototype
 * Description: replaces variables in the tokenized string
 * @i: struct
 * Return: 1 (Success), 0 otherwise
 */
int replace_variables(simpsh_t *i)
{
int a = 0;
list_t *node;
for (a = 0; i->av[a]; a++)
{
if (i->av[a][0] != '$' || !i->av[a][1])
continue;
if (!_strcmp(i->av[a], "$?"))
{
replace_str(&(i->av[a]),
_strdup(num_str(i->code, 10, 0)));
continue;
}
if (!_strcmp(i->av[a], "$$"))
{
replace_str(&(i->av[a]),
_strdup(num_str(getpid(), 10, 0)));
continue;
}
node = node_prefix(i->envt, &i->av[a][1], '=');
if (node)
{
replace_str(&(i->av[a]),
_strdup(_strchr(node->str, '=') + 1));
continue;
}
replace_str(&i->av[a], _strdup(""));
}
return (0);
}
/**
 * replace_str - Function prototype
 * Description: replaces string
 * @old: string char
 * @new: string char
 * Return: 1 (Success), 0 otherwise
 */
int replace_str(char **old, char *new)
{
free(*old);
{
*old = new;
return (1);
}
}
