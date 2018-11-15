#include "bengie.h"

int (*_get_built_ins(char *s))(int, int)
{
        op_t ops[] = {
                {"env", print_env},
                {"exit", builtin_exit},
                {"cd", cd1},
                {"ls", ls_function}
                {NULL, NULL}
        };

        int i;

        i = 0;
        while (ops[i].op != NULL)
        {
                if (strcmp(ops[i].op, *s) == 0)
                {
                        return (ops[i].f);
                }
                i++;
        }
        return (NULL);
}
