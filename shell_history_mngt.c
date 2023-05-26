#include "main.h"
/**
 * retrieve_hist_file - Function prototype
 * Description: retrieves history file path.
 * @i: struct
 * Return: history file string
 */
char *retrieve_hist_file(simpsh_t *i)
{
char *buff, *dir;
dir = custom_getenv(i, "HOME=");
if (!dir)
return (NULL);
buff = malloc(sizeof(char) * (_strlen(dir) + _strlen(RECORD_HIST) + 2));
if (!buff)
return (NULL);
buff[0] = 0;
_strcpy(buff, dir);
_strcat(buff, "/");
_strcat(buff, RECORD_HIST);
return (buff);
}
/**
 * mod_hist - Function prototype
 * Description: creates a file, or appends to an existing file
 * @i: struct
 * Return: 1 (Success), -1 (Failure)
 */
int mod_hist(simpsh_t *i)
{
ssize_t fd;
char *filename = retrieve_hist_file(i);
list_t *node = NULL;
if (!filename)
return (-1);
fd = open(filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
free(filename);
if (fd == -1)
return (-1);
for (node = i->hist; node; node = node->next)
{
custom_putsfd(node->str, fd);
custom_putcfd('\n', fd);
}
custom_putcfd(BUFF_F, fd);
close(fd);
return (1);
}
/**
 * read_hist - Function prototype
 * Description: reads history from file
 * @i: struct
 * Return: hist total (Success), 0 otherwise
 */
int read_hist(simpsh_t *i)
{
int a, last = 0, lc = 0;
ssize_t fd, rdlen, fsize = 0;
struct stat st;
char *buff = NULL, *filename = retrieve_hist_file(i);
if (!filename)
return (0);
fd = open(filename, O_RDONLY);
free(filename);
if (fd == -1)
return (0);
if (!fstat(fd, &st))
fsize = st.st_size;
if (fsize < 2)
return (0);
buff = malloc(sizeof(char) * (fsize + 1));
if (!buff)
return (0);
rdlen = read(fd, buff, fsize);
buff[fsize] = 0;
if (rdlen <= 0)
return (free(buff), 0);
close(fd);
for (a = 0; a < fsize; a++)
if (buff[a] == '\n')
{
buff[a] = 0;
add_hist_list(i, buff + last, lc++);
last = a + 1;
}
if (last != a)
add_hist_list(i, buff + last, lc++);
free(buff);
i->total_hist = lc;
while (i->total_hist-- >= MAX_RECORD)
delete_node_at_index(&(i->hist), 0);
rearrange_hist(i);
return (i->total_hist);
}
/**
 * add_hist_list - Function prototype
 * Description: adds entry to a history linked list
 * @i: struct
 * @buff: char string
 * @lc: int
 * Return: Always 0
 */
int add_hist_list(simpsh_t *i, char *buff, int lc)
{
list_t *node = NULL;
if (i->hist)
node = i->hist;
add_node_end(&node, buff, lc);
if (!i->hist)
i->hist = node;
return (0);
}
/**
 * rearrange_hist - Function prototype
 * Description: renumbers the history linked list after changes
 * @i: struct
 * Return: updated hist total
 */
int rearrange_hist(simpsh_t *i)
{
list_t *node = i->hist;
int a = 0;
while (node)
{
node->num = a++;
node = node->next;
}
return (i->total_hist = a);
}
