#include "bengie.h"

/**
 * sigHandler - a function that handles CTRL+C
 * @bob: the signal
 *
 * Return: Nothing
 */

void sigHandler(int bob)
{
	(void) bob;

	write(STDOUT_FILENO, "\nBengie$ ", 9);
}

/**
 * main - Runs a simple UNIX shell
 *
 * Return: Nothing
 */

int main(void)
{
	pid_t child_pid = 0;
	char *buffer; /** gets command line */
	size_t buffsize = 0;
	int status;
	char *token[1024];
	int i = 1;
	ssize_t chars;
	char **argv = NULL;

	while (1)
	{
		/*interactive mode*/
		if (isatty(0))
		{
			write(STDIN_FILENO, "Bengie$ ", 8);
		}
		signal(SIGINT, sigHandler);

/*write(STDIN_FILENO, "$ ", 2);*/
		child_pid = fork();
		if (child_pid == -1)
		{
			return (-1);
		}
		if (child_pid == 0)
		{
			chars = (getline(&buffer, &buffsize, stdin));

			if (chars == -1)
			{
				if (isatty(0))
				{
					/*handles ctrl + D*/
					write(STDIN_FILENO, "\n", 1);
				}
				free(buffer);
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

			if (strcmp(argv[0], "env") == 0)
			{
				print_env();
				free(argv);
				break;
			}
		}
		if (child_pid > 0)
		{
			wait(&status);
		}
		free(buffer);
	}
	return (0);
}
