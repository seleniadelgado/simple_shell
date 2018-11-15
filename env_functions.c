#include "bengie.h"

int matchpath(const char *s1, char *s2)
{
        int i = 0;

        while ((s1[i] == s2[i]) && (s1[i] != '\0'))
        {
                i++;
        }
        if ((s1[i] == '\0') && (s2[i] == '='))
        {
                return (0);
        }
        else
        {
                return (-1);
        }
}

char *_getenv(const char *name)
{
        int index;
        /* int length;*/

        /*length = strlen (name);*/

        for (index = 0; environ[index]; index++)
        {
                /*if (strncmp(name, environ[index], length) == 0)
                {
                        return (environ[index]);
                        }*/
		if (matchpath(name, environ[index]) == 0)
                {
                        return (environ[index]);
                }
        }
        return (NULL);
}



/* Where the environment variable 'PATH' is set to a value. */

int main(void)
{
        char *string;
        char *name = "PATH";
        int i;

	string = _getenv(name);

        for (i = 0; string[i]; i++)
                ;
        write(STDIN_FILENO, string, i);
        write(STDIN_FILENO, "\n", 1);
        return (0);
}
