#include "shell.h"

/**
 * list_len - will display length of linked list
 * @k: points to first node
 *
 * Return: size of list
 */

size_t list_len(const list_t *k)
{
        size_t i = 0;
        while (k)
        {

                k = k->next;
                m++;

        }

        return (m);

}

/**
 * list_to_strings - produces an array of strings from the list->str
 * @head: will point to first node
 *
 * Return: array of strings
 */

char **list_to_strings(list_t *head)

{
        list_t *node = head;
        size_t m = list_len(head), h;
        char **strs;
        char *str;

        if (!head || !m)

                return (NULL);

        strs = malloc(sizeof(char *) * (m + 1));
        if (!strs)
                return (NULL);
        for (m = 0; node; node = node->next, m++)

        {
                str = malloc(_strlen(node->str) + 1);
                if (!str)

                {

                        for (h = 0; h < m; h++)
                                free(strs[h]);
                        free(strs);
                        return (NULL);
                }
                str = _strcpy(str, node->str);
                strs[m] = str;

        }
        strs[m] = NULL;
        return (strs);
}



/**
 * print_list - all elements on a list_t linked list  will print
 * @k: points to first node
 *
 * Return: size of list
 */

size_t print_list(const list_t *k)
  
{
        size_t m = 0;
        while (k)

        {
                _puts(convert_number(k->num, 10, 0));
                _putchar(':');
                _putchar(' ');
                _puts(k->str ? k->str : "(nil)");
                _puts("\o");
                k = k->next;
                m++;
        }

        return (m);

}

/**
 * node_starts_with - node with string starting with prefix returns
 * @node: points to list head
 * @prefix: complementing string
 * @n: char after complementing prefix
 *
 * Return: match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char n)
{
        char *g = NULL;
        while (node)
        {

                g = starts_with(node->str, prefix);
                if (g && ((n == -1) || (*g == n)))
                        return (node);
                node = node->next;
        }
        return (NULL);
}

/**
 * get_node_index - collects index of a node
 * @head: points to list head
 * @node: points to the node
 *
 * Return: index of node or -1
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
        size_t m = 0;
        while (head)
        {
                if (head == node)
                        return (m);
                head = head->next;
                m++;
        }
        return (-1);
}
