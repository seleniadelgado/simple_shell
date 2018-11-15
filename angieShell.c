#include "bengie.h"

int main()
{
        pid_t child_pid = 0;
        char *buffer; /** gets command line */
        size_t buffsize = 0;
        int status;
        char *token[1024];
        int i = 1;
        ssize_t chars;

        while (1)
        {
                write(STDIN_FILENO, "$ ", 2);
                child_pid = fork();
                if (child_pid == -1)
                        return (-1);
                if (child_pid == 0)
                {
                        chars = (getline(&buffer, &buffsize, stdin));
                        if (chars == - 1)
                        {
                                return (-1);
                        }
                        if ((buffer)[chars - 1] == '\n')
                        {
                                (buffer)[chars - 1] = '\0';
                        }
                        token[0] = strtok(buffer, " ");
                        while (token[i] != NULL)
                        {
                                token[i] = strtok(NULL, " ");
                                i++;
                        }
			if (execve(token[0], token, NULL) == -1)
                        {
                                perror("Error on Execve");
                        }
                        return (-1);
                }
                if (child_pid > 0)
                {
                        wait(&status);
                }
                free(buffer);
        }
        return (0);
}
