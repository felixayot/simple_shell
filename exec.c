#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * exec - A Function that executes the command
 * @cmd: Pointer to the command a user inputs
 * Return: Returns to the function running the shell
 */
int exec(char *cmd)
{
	char *envp[] = {NULL};
	pid_t pid;

	if (strcmp(cmd, "exit") == 0)
	{
		exit(0);
	}
	pid = fork();

	if (pid == -1)
	{
		perror("fork failed");
		exit(1);
	}
	else if (pid == 0)
	{
		char *argv[3];

		argv[0] = "/bin/sh";
		argv[1] = "-c";
		argv[2] = cmd;
		argv[3] = NULL;

		execve("/bin/sh", argv, envp);
		perror("execve failed");
		exit(1);
	}
	else
	{
		wait(NULL);
		return (1);
	}
}
