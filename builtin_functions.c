#include "bengie.h"

/**
 * _get_built_ins - a function that goes through the data structure.
 * @s:
 * @args:
 *
 * Return: function pointer.
 */

char (*_get_built_ins(char *s))(char **agrs, char **hj)
{
	op_t ops[] = {
		{"env", print_env},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (_strcmp(ops[i].op, *s) == 0)
		{
			break;
		}
		i++;
	}
	return (ops[i].f);
}
