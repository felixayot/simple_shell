#include "main.h"
/**
 * init_simpsh - Function prototype
 * Description: initializes simpsh_t struct
 * @i: struct
 * Return: void
 */
void init_simpsh(simpsh_t *i)
{
i->ag = NULL;
i->av = NULL;
i->pth = NULL;
i->ac = 0;
}
/**
 * set_simpsh - Function prototype
 * Description: initializes simpsh_t struct
 * @i: struct
 * @argv: argument vector
 * Return: void
 */
void set_simpsh(simpsh_t *i, char *argv[])
{
int a = 0;
i->file_name = argv[0];
if (i->ag)
{
i->av = strtow(i->ag, " \t");
if (!i->av)
{
i->av = malloc(sizeof(char *) * 2);
if (i->av)
{
i->av[0] = _strdup(i->ag);
i->av[1] = NULL;
}
}
for (a = 0; i->av && i->av[a]; a++)
;
i->ac = a;
replace_alias(i);
replace_variables(i);
}
}
/**
 * free_simpsh - Function prototype
 * Description: frees simpsh_t struct family
 * @i: struct
 * @all: 1 (Success)
 */
void free_simpsh(simpsh_t *i, int all)
{
free_str(i->av);
i->av = NULL;
i->pth = NULL;
if (all)
{
if (!i->buff)
free(i->ag);
if (i->envt)
free_list(&(i->envt));
if (i->hist)
free_list(&(i->hist));
if (i->alias)
free_list(&(i->alias));
free_str(i->envr);
i->envr = NULL;
pointer_free((void **)i->buff);
if (i->inputsize > 2)
close(i->inputsize);
_putchar(BUFF_F);
}
}
