#include "main.h"
/**
 * read_cmd - Function that reads the line of command that the user inputs
 *
 * Return: Nothing NULL if end of file is reahed
 */
char *read_cmd(void)
{
	char *len = NULL;
	size_t line = 0;
	ssize_t readline;

	readline = getline(&len, &line, stdin);

	if (readline == -1)
	{
	_putchar('\n');
		if (feof(stdin))
		{
			free(len);
			return (NULL);
		}
		else
		{
			perror("getline");
			free(len);
			exit(EXIT_FAILURE);
		}
	}
	return (len);
}
