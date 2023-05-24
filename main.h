#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdbool.h>

void exe_cmd(char **argv);
extern char **environ;
int str_tokens(char *buff, const char *separator, char **exec_argv);

#endif
