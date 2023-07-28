#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2
#define USE_GETLINE 0
#define USE_STRTOK 0
#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;
/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct simpsh_info - contains pseudo-arguments to pass into a function,
 * allowing uniform prototype for function pointer struct
 * @arg: a string generated from getline containing arguements
 * @argv:an array of strings generated from arg
 * @path: a string path for the current command
 * @argc: the argument count
 * @line_count: the error count
 * @err_num: the error code for exit()s
 * @linecount_flag: if on count this line of input
 * @fname: the program filename
 * @env: linked list local copy of environ
 * @environ: custom modified copy of environ from LL env
 * @history: the history node
 * @alias: the alias node
 * @env_changed: on if environ was changed
 * @status: the return status of the last exec'd command
 * @cmd_buf: address of pointer to cmd_buf, on if chaining
 * @cmd_buf_type: CMD_type ||, &&, ;
 * @readfd: the fd from which to read line input
 * @histcount: the history line number count
 */
typedef struct simpsh_info
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf;
	int cmd_buf_type;
	int readfd;
	int histcount;
} simpsh_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
		0, 0, 0}

/**
 * struct builtin - contains a builtin string and related function
 * @type: the builtin command flag
 * @func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(simpsh_t *info);
} builtin_table;

/* SHELL_MAIN_LOOP FUNCTION PROTOTYPES */
int hsh(simpsh_t *info, char **av);
int find_builtin(simpsh_t *info);
void find_cmd(simpsh_t *info);
void fork_cmd(simpsh_t *info);

/* SHELL_LOCATE_EXE FUNCTION PROTOTYPES */
int is_cmd(simpsh_t *info, char *path);
char *dup_chars(char *pathstr, int start, int stop);
char *find_path(simpsh_t *info, char *pathstr, char *cmd);

/* SHELL_ERROR_STRINGS FUNCTION PROTOTYPES */
void _eputs(char *str);
int _eputchar(char c);
int _putfd(char c, int fd);
int _putsfd(char *str, int fd);

/* SHELL_STRING_COPYING FUNCTION PROTOTYPES */
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
void _puts(char *str);
int _putchar(char c);

/* SHELL_STRING_MANIPULATION FUNCTION PROTOTYPES */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *starts_with(const char *haystack, const char *needle);
char *_strcat(char *dest, char *src);

/* SHELL_MORE_STRING_MANIPULATION FUNCTION PROTOTYPES */
char *_strncpy(char *dest, char *src, int n);
char *_strncat(char *dest, char *src, int n);
char *_strchr(char *s, char c);

/* SHELL_STRING_TOKENS FUNCTION PROTOTYPES */
char **strtow(char *str, char *d);
char **strtow2(char *str, char d);

/* SHELL_MEM_MNGT FUNCTION PROTOTYPES */
char *_memset(char *s, char b, unsigned int n);
void ffree(char **pp);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* SHELL_FREE_POINTER FUNCTION PROTOTYPE */
int bfree(void **);

/* SHELL_SIGNATURE FUNCTION PROTOTYPES */
int interactive(simpsh_t *info);
int is_delim(char c, char *delim);
int _isalpha(int c);
int _atoi(char *s);

/* SHELL_MORE_ERROR_HANDLING FUNCTION PROTOTYPES */
int _erratoi(char *s);
void print_error(simpsh_t *info, char *estr);
int print_d(int input, int fd);
char *convert_number(long int num, int base, int flags);
void remove_comments(char *buf);

/* SHELL_DIRECTORY_HELP FUNCTION PROTOTYPES */
int _myexit(simpsh_t *info);
int _mycd(simpsh_t *info);
int _myhelp(simpsh_t *info);

/* SHELL_ALIAS_MNGT FUNCTION PROTOTYPES */
int _myhistory(simpsh_t *info);
int set_alias(simpsh_t *info, char *str);
int unset_alias(simpsh_t *info, char *str);
int _myalias(simpsh_t *info);
int print_alias(list_t *node);

/* SHELL_GETLINE FUNCTION PROTOTYPES */
ssize_t input_buf(simpsh_t *info, char **buf, size_t *len);
ssize_t get_input(simpsh_t *info);
ssize_t read_buf(simpsh_t *info, char *buf, size_t *i);
int _getline(simpsh_t *info, char **ptr, size_t *length);
void sigintHandler(int sig_num);

/* SHELL_INIT_STRUCT FUNCTION PROTOTYPES */
void clear_info(simpsh_t *info);
void set_info(simpsh_t *info, char **av);
void free_info(simpsh_t *info, int all);

/* SHELL_ENV_VARIABLES FUNCTION PROTOTYPES */
char *_getenv(simpsh_t *info, const char *name);
int _myenv(simpsh_t *info);
int _mysetenv(simpsh_t *info);
int _myunsetenv(simpsh_t *info);
int populate_env_list(simpsh_t *info);

/* SHELL_ENV_VAR_MANIPULATION FUNCTION PROTOTYPES */
char **get_environ(simpsh_t *info);
int _unsetenv(simpsh_t *info, char *var);
int _setenv(simpsh_t *info, char *var, char *value);

/* SHELL_HISTORY_MNGT FUNCTION PROTOTYPES */
char *get_history_file(simpsh_t *info);
int write_history(simpsh_t *info);
int read_history(simpsh_t *info);
int build_history_list(simpsh_t *info, char *buf, int linecount);
int renumber_history(simpsh_t *info);

/* SHELL_LINKED_LIST_MNGT FUNCTION PROTOTYPES */
list_t *add_node(list_t **head, const char *str, int num);
list_t *add_node_end(list_t **head, const char *str, int num);
size_t print_list_str(const list_t *h);
int delete_node_at_index(list_t **head, unsigned int index);
void free_list(list_t **head_ptr);

/* SHELL_MORE_LINKED_LIST FUNCTION PROTOTYPES */
size_t list_len(const list_t *h);
char **list_to_strings(list_t *head);
size_t print_list(const list_t *h);
list_t *node_starts_with(list_t *node, char *prefix, char c);
ssize_t get_node_index(list_t *head, list_t *node);

/* SHELL_LOGIC_OPS FUNCTION PROTOTYPES */
int is_chain(simpsh_t *info, char *buf, size_t *p);
void check_chain(simpsh_t *info, char *buf, size_t *p, size_t i, size_t len);
int replace_alias(simpsh_t *info);
int replace_vars(simpsh_t *info);
int replace_string(char **old, char *new);

#endif /* _MAIN_H_ */
