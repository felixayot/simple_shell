#include "main.h"
/**
 * str_tokens - tokenizes CLI arguments
 * @buff: string char
 * @separator: string char
 * @exec_argv: string char
 * Return: 0 (Success)
 */
int str_tokens(char *buff, const char *separator, char **exec_argv)
{
char *buff_cpy = NULL;
char *tok;
int indx;
int tok_count = 0;
buff_cpy = strdup(buff);
if (buff_cpy == NULL)
{
perror("Memory allocation failed");
return (-1);
}
tok = strtok(buff, separator);
while (tok != NULL)
{
tok = strtok(NULL, separator);
tok_count++;
}
tok_count++;
if (tok_count > 256)
{
perror("Too many arguments");
return (-1);
}
indx = 0;
tok = strtok(buff_cpy, separator);
for (; tok != NULL; indx++)
{
exec_argv[indx] = strdup(tok);
tok = strtok(NULL, separator);
}
exec_argv[indx] = NULL;
free(buff_cpy);
return (0);
}
