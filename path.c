#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
#include <string.h>

/**
 * cmd_path - A funtion that handles the path
 * @cmd: Pointer to the command we are checking
 * Return: Returns the path
 */
char *cmd_path(char *cmd)
{
	char *path = getenv("PATH");
	char *tok = strtok(path, ":");
	char *cmdpath = NULL;
	size_t cmdl, pathl, tl;

	cmdl = strlen(cmd);

	while (tok != NULL)
	{
		pathl = strlen(tok);
		tl = pathl + cmdl + 2;

		cmdpath = malloc(tl);

		if (!cmdpath)
		{
			perror("Malloc was not successful");
			exit(EXIT_FAILURE);
		}
		memcpy(cmdpath, tok, pathl);
		cmdpath[pathl] = '/';
		memcpy(cmdpath + pathl + 1, cmd, cmdl + 1);

		if (access(cmdpath, F_OK) == 0)
			return (cmdpath);
		free(cmdpath);
		cmdpath = NULL;

		tok = strtok(NULL, ":");
	}
	return (cmdpath);
}

