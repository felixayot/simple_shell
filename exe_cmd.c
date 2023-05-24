#include "main.h"
/**
 * exe_cmd - executes CLI arguments
 * @argv: string pointer
 * Return: void
 */
void exe_cmd(char **argv)
{
char *cmd = NULL;
char *full_path = NULL;
char *token;
char *path = getenv("PATH");
if (argv != NULL)
{
cmd = argv[0];
if (execve(cmd, argv, NULL) == -1)
{
token = strtok(path, ":");
while (token != NULL)
{
full_path = malloc(strlen(token) + strlen(cmd) + 2);
if (full_path != NULL)
{
sprintf(full_path, "%s/%s", token, cmd);
if (execve(full_path, argv, environ) != -1)
{
free(full_path);
}
free(full_path);
}
token = strtok(NULL, ":");
}
perror(cmd);
}
}
}
