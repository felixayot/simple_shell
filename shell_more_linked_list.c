#include "main.h"
/**
 * list_length - Function prototype
 * Description: determines length of linked list
 * @h: pointer to head node
 * Return: list size
 */
size_t list_length(const list_t *h)
{
size_t i = 0;
while (h)
{
h = h->next;
i++;
}
return (i);
}
/**
 * list_to_strings - Function prototype
 * Description: returns an array of strings of the list->str
 * @head: pointer to head node
 * Return: array of strings
 */
char **list_to_strings(list_t *head)
{
list_t *node = head;
size_t i = list_length(head), j;
char **strs;
char *str;
if (!head || !i)
return (NULL);
strs = malloc(sizeof(char *) * (i + 1));
if (!strs)
return (NULL);
for (i = 0; node; node = node->next, i++)
{
str = malloc(_strlen(node->str) + 1);
if (!str)
{
for (j = 0; j < i; j++)
free(strs[j]);
free(strs);
return (NULL);
}
str = _strcpy(str, node->str);
strs[i] = str;
}
strs[i] = NULL;
return (strs);
}
/**
 * print_list - Function prototype
 * Description: prints all elements of a list_t linked list
 * @h: pointer to head node
 * Return: list size
 */
size_t print_list(const list_t *h)
{
size_t i = 0;
while (h)
{
_puts(num_str(h->num, 10, 0));
_putchar(':');
_putchar(' ');
_puts(h->str ? h->str : "(nil)");
_puts("\n");
h = h->next;
i++;
}
return (i);
}
/**
 * node_prefix - Function prototype
 * Description: returns node whose string starts with prefix
 * @node: pointer to list head
 * @prefix: char string
 * @c: the next character after prefix to match
 * Return: match node or null
 */
list_t *node_prefix(list_t *node, char *prefix, char c)
{
char *p = NULL;
while (node)
{
p = str_str(node->str, prefix);
if (p && ((c == -1) || (*p == c)))
return (node);
node = node->next;
}
return (NULL);
}
/**
 * get_node_index - Function prototype
 * Description: gets the index of a node
 * @head: pointer to list head
 * @node: pointer to the node
 * Return: index of node or -1 (Failure)
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
size_t i = 0;
while (head)
{
if (head == node)
return (i);
head = head->next;
i++;
}
return (-1);
}
