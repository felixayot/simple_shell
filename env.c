#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * env - A function that prints the environment
 *
 * Return: Returns nothing
 */
void env(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
