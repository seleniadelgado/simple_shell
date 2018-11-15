#include "bengie.h"

/**
 * add_end_node - adds a new node at the end of a list_t linked list
 * @head: a pointer to the first node in a linked list
 * @str: the string to be assigned to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */

list_t *add_node_end(list_t **head, char *str)
{
        list_t *new_node, *i;

        new_node = malloc(sizeof(list_t));
        if (new_node == NULL)
        {
                return (NULL);
        }

        new_node->str = _strdup(str);
        new_node->next = NULL;

        if (*head == NULL)
        {
                *head = new_node;
        }
        else
        {
                for (i = *head; i->next != NULL; i = i->next)
                {
                        ;
                }
                i->next = new_node;
        }
	return (new_node);
}


void build_linked_list(char *path, list_t **head)
{
        char *token;

        token = strtok(path, ":");
        while (token != NULL)
        {
                add_node_end(head, token);
                token = strtok(NULL, ":");
        }
}

/**
 * free_list - a function that frees a list_t linked lists
 * @head: a pointer to the first node
 *
 * Return: nothing
 */

void free_list(list_t *head)
{
        list_t *temp;

        while (head != NULL)
        {
                temp = head;
                free(tmp->str);
                head = head->str;
                free(tmp);
        }

}
