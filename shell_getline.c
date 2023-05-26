#include "main.h"
/**
 * _getline - gets the next line of input from STDIN
 * @i: parameter struct
 * @ptr: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int _getline(simpsh_t *i, char **ptr, size_t *length)
{
static char buf[READ_BUFFSIZE];
static size_t a, len;
size_t k;
ssize_t r = 0, s = 0;
char *p = NULL, *new_p = NULL, *c;
p = *ptr;
if (p && length)
s = *length;
if (a == len)
a = len = 0;
r = input_line(i, NULL, &len);
if (r == -1 || (r == 0 && len == 0))
return (-1);
c = _strchr(buf + a, '\n');
k = c ? 1 + (unsigned int)(c - buf) : len;
new_p = manual_realloc(p, s, s ? s + k : k + 1);
if (!new_p)
return (p ? free(p), -1 : -1);
if (s)
_strncat(new_p, buf + a, k - a);
else
_strncpy(new_p, buf + a, k - a + 1);
s += k - a;
a = k;
p = new_p;
if (length)
*length = s;
*ptr = p;
return (s);
}
/**
 * input_line - gets CLI arguments
 * @i: struct
 * @buffer: pointer string
 * @len: int
 * Return: input size
 */
ssize_t input_line(simpsh_t *i, char *buffer[], size_t *len)
{
ssize_t r = 0;
size_t pl = 0;
if (!*len)
{
free(*buffer);
*buffer = NULL;
signal(SIGINT, handle_sigint);
#if USE_GETLINE
r = getline(buf, &len_p, stdin);
#else
r = _getline(i, buffer, &pl);
#endif
if (r > 0)
{
if ((*buffer)[r - 1] == '\n')
{
(*buffer)[r - 1] = '\0';
r--;
}
i->buffsize_code = 1;
de_comments(*buffer);
add_hist_list(i, *buffer, i->total_hist++);
{
*len = r;
i->buff = buffer;
}
}
}
return (r);
}
/**
 * line_only - Function prototype
 * Description: reads a line without the newline
 * @i: struct
 * Return: input size
 */
ssize_t line_only(simpsh_t *i)
{
static char *buf;
static size_t a, j, len;
ssize_t r = 0;
char **buf_p = &(i->ag), *p;
_putchar(BUFF_F);
r = input_line(i, &buf, &len);
if (r == -1)
return (-1);
if (len)
{
j = a;
p = buf + a;
continue_chain(i, buf, &j, a, len);
while (j < len)
{
if (is_logical_operator(i, buf, &j))
break;
j++;
}
a = j + 1;
if (a >= len)
{
a = len = 0;
i->cmdtype = NORMAL_CMD;
}
*buf_p = p;
return (_strlen(p));
}
*buf_p = buf;
return (r);
}
/**
 * read_input - Function prototype
 * Description: reads a buffer
 * @i: struct
 * @buf: buffer
 * @a: size
 * Return: inputsize
 */
ssize_t read_input(simpsh_t *i, char *buf, size_t *a)
{
ssize_t r = 0;
if (*a)
return (0);
r = read(i->inputsize, buf, READ_BUFFSIZE);
if (r >= 0)
i->input = r;
return (r);
}
/**
 * handle_sigint - Function prototype
 * Description: prints a newline and the prompt when CTRL+C is initiated
 * @sig_num: int
 * Return: void
 */
void handle_sigint(__attribute__((unused))int sig_num)
{
_puts("^C");
_puts("\n");
_puts("$ ");
_putchar(BUFF_F);
}
