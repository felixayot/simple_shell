#ifndef _MAIN_H_
#define _MAIN_H_

char *read_cmd(void);
void shell_l(void);
void prompt(void);
int exec(char *cmd);
char *cmd_path(char *cmd);

#endif
