#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void env(void);
extern char **environ;
char *read_cmd(void);
void shell_l(void);
void prompt(void);
int exec(char *cmd);
char *cmd_path(char *cmd);
int _putchar(char c);

#endif
