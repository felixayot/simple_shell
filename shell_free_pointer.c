#include "main.h"
/**
 * pointer_free - Function prototype
 * Description: frees a pointer
 * @p: pointer address
 * Return: 1 (Success), otherwise 0.
 */
int pointer_free(void **p)
{
if (p && *p)
free(*p);
*p = NULL;
return (1);
return (0);
}
