#ifndef _BENGIE_H
#define _BENGIE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

extern char** environ;

/**
 *
 *
 */

typedef struct list_s
{
        char *str;
        struct list *next;
} list_t;

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
        char *op;
        int (*f)(char *a);
} op_t;

list_t *add_node_end(list_t **head, char *str);
void build_linked_list(char *path, list_t **head);
void free_list(list_t *head);
int matchpath(const char *s1, char *s2);
char *_getenv(const char *name);
int print_PATH_ENV(void);
int (*_get_built_ins(char *s))(int, int);

#endif
