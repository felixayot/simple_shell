#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <errno.h>

#define BUFF_F -1
#define NORMAL_CMD 0
#define OR_CMD 1
#define AND_CMD	2
#define CHAIN_CMD 3
#define LWCASE_CONV	1
#define UNSIGN_CONV	2
#define GETLINE_FUNC 0
#define STRTOK_FUNC 0
#define RECORD_HIST ".history_record"
#define MAX_RECORD 4096
#define READ_BUFFSIZE 1024
#define WRITE_BUFFSIZE 1024

/**
 * struct strlst - define struct type for string lists
 * @num: int
 * @str: string pointer
 * @next: pointer struct to next node
 */
typedef struct strlst
{
int num;
char *str;
struct strlst *next;
} list_t;

/**
 * struct parafunc - define struct typepasses paramaters to functions
 * @ag: pointer string
 * @av: pointer to array of strings
 * @pth: pointer string
 * @ac: arguments count
 * @err_code: int
 * @buffsize_code: int
 * @input: int
 * @file_name: string pointer
 * @envt: stuct
 * @envr: array of string pointers
 * @hist: struct
 * @alias: struct
 * @newenviron: int
 * @code: int
 * @buff: array of string pointers
 * @cmdtype: int
 * @inputsize: int
 * @total_hist: int
 */
typedef struct parafunc
{
char *ag;
char **av;
char *pth;
int ac;
unsigned int input;
int err_code;
int buffsize_code;
char *file_name;
char **envr;
int newenviron;
int code;
char **buff;
int cmdtype;
int inputsize;
int total_hist;
list_t *envt;
list_t *hist;
list_t *alias;
} simpsh_t;

#define SHELL_VALUE \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, 0, 0, NULL, 0, 0, 0, \
		NULL, NULL, NULL}


/**
 * struct defbuilt - define struct for default functions
 * @type: int
 * @func: int
 */
typedef struct defbuilt
{
char *type;
int (*func)(simpsh_t *);
} default_funcs;
int simple_shell(simpsh_t *i, char *argv[]);
int find_default(simpsh_t *i);
void find_cmd(simpsh_t *i);
void _fork(simpsh_t *i);
int is_exe(char *path);
char *chars_cpy(char *pathstr, int start, int stop);
char *find_path(simpsh_t *i, char *pathstr, char *cmd);
int loophsh(char **);
void custom_puts(char *c);
int _putchar(char c);
int custom_putcfd(char c, int fd);
int custom_putsfd(char *str, int fd);
int _strlen(char *s);
int _strcmp(char *str1, char *str2);
char *str_str(const char *haystack, const char *needle);
char *_strcat(char *new, char *str);
char *_strcpy(char *new, char *str);
char *_strdup(const char *str);
void _puts(char *str);
char *_strncpy(char *new, char *str, int n);
char *_strncat(char *new, char *str, int n);
char *_strchr(char *s, char c);
char **strtow(char *str, char *sp);
char **custom_strtow(char *str, char sp);
char *_memset(char *s, char b, unsigned int n);
void free_str(char **str);
void *manual_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int pointer_free(void **p);
int is_terminal(simpsh_t *i);
int is_separator(char c, char *separator);
int _isalpha(int c);
int _atoi(char *s);
int str_num(char *s);
void print_error(simpsh_t *i, char *str);
int print_float(int input, int fd);
char *num_str(long int num, int base, int flags);
void de_comments(char *line);
int custom_exit(simpsh_t *i);
int custom_cd(simpsh_t *i);
int init_help(simpsh_t *i);
int print_alias(list_t *node);
int set_alias(simpsh_t *i, char *str);
int hist_record(simpsh_t *i);
int custom_alias(simpsh_t *i);
int release_alias(simpsh_t *i, char *str);
ssize_t input_line(simpsh_t *i, char **buffer, size_t *len);
ssize_t read_input(simpsh_t *i, char *buf, size_t *a);
ssize_t line_only(simpsh_t *i);
void handle_sigint(__attribute__((unused))int sig_num);
void init_simpsh(simpsh_t *i);
void set_simpsh(simpsh_t *i, char *argv[]);
void free_simpsh(simpsh_t *i, int all);
char **cpy_envr(simpsh_t *i);
int custom_unsetenv(simpsh_t *i, char *v);
int custom_setenv(simpsh_t *i, char *v, char *content);
extern char **environ;
int _printenv(simpsh_t *i);
char *custom_getenv(simpsh_t *i, const char *name);
int init_setenv(simpsh_t *i);
int init_unsetenv(simpsh_t *i);
int fillup_env(simpsh_t *i);
char *retrieve_hist_file(simpsh_t *i);
int mod_hist(simpsh_t *i);
int read_hist(simpsh_t *i);
int add_hist_list(simpsh_t *i, char *buff, int lc);
int rearrange_hist(simpsh_t *i);
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);
size_t list_length(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_prefix(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);
int is_logical_operator(simpsh_t *i, char *line, size_t *p);
void continue_chain(simpsh_t *i, char *buff, size_t *p, size_t a, size_t len);
int replace_alias(simpsh_t *t);
int replace_variables(simpsh_t *t);
int replace_str(char **old, char *new);

#endif
