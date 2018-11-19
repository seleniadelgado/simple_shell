#ifndef _BENGIE_H
#define _BENGIE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

extern char **environ;

/**
 * struct op - Struct op
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(char *s, char **agrs);
} op_t;

int matchpath(const char *s1, char *s2);
char *_getenv(const char *name);
int print_PATH_ENV(void);
void print_env(void);
char (*_get_built_ins(char *s))(char **agrs, char **hj);
int _strcmp(char *s1, char *s2);

#endif
