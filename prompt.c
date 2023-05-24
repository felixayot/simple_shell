#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * prompt - Function that displays our prompt
 *
 * Return: Returns Nothing
 */
void prompt(void)
{
	write(STDOUT_FILENO, "$ ", 2);
}
