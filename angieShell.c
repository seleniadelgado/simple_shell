#include "bengie.h"

void sigintHandler(int bob)
{
        (void) bob;

        write(STDOUT_FILENO, "\nBengie$ ", 9);
}

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
                if (isatty(0))
                {
                        write(STDIN_FILENO, "Bengie$ ", 8);
                }
                signal(SIGINT, sigintHandler);

                /*write(STDIN_FILENO, "$ ", 2);*/
                child_pid = fork();
                if (child_pid == -1)
                        return (-1);
                if (child_pid == 0)
                {
                        chars = (getline(&buffer, &buffsize, stdin));

                        if (chars == - 1)
			{
                                if (isatty(0))
                                        write(STDIN_FILENO, "\n", 1);
                                free(buffer);
                                return (-1);
                        }
                        if (chars == 0)
                        {
                                if (isatty(0))
                                {
                                        write(STDIN_FILENO, "\n", 1);
                                        continue;
                                }
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
                        /*if (strcmp(argv[0], "env") == 0)
                        {
                                print_env();
                                free(argv);
                                break;
                                }*/
		}
                if (child_pid > 0)
                {
                        wait(&status);
                }
                free(buffer);
        }
        return (0);
}
