#include "bengie.h"

int (*_get_built_ins(char *s))(char **agrs)
{
	op_t ops[] = {
		{"env", print_env},
		{"exit", builtin_exit},
		{NULL, NULL}
	};

	int i;

	i = 0;
	while (ops[i].op != NULL)
	{
		if (strcmp(ops[i].op, *s, strlen(ops[i].op)) == 0)
		{
			break;
		}
		i++;
	}
	return (ops[i].f);
}
