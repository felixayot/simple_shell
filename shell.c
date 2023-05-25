#include "main.h"
/**
 * shell_l - function that runs the shell. It reads and executes the shell
 *
 * Return: Returns Nothing
 */
void shell_l(void)
{
	char *len;
	int i = 0;
	int exit = 0;
	int stat = 1;

	while (stat)
	{
		prompt();
		len = read_cmd();
		if (!len)
		{
			break;
		}
		while (len[i] != '\0')
		{
			if (len[i] != ' ' && len[i] != '\n')
			{
				exit = 0;
				break;
			}
			i++;
		}
		if (exit)
		{
			break;
		}
		if (strcmp(len, "exit\n") == 0)
		{
			break;
		}
		else if (strcmp(len, "ls\n") == 0)
		{
			system("/bin/ls");
		}
		else
		{
			stat = exec(len);
		}
		free(len);
	}
}
