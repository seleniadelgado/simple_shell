#include "bengie.h"
/**
 * shell - function.
 *
 *
 */
int main(void)
{
	pid_t child_pid;
	char *buffer;
	size_t buffsize = 0;
	int status;
	char *token[500];
	int i = 1;
	ssize_t chars;

	while (1)
	{
		child_pid = fork();
		if (child_pid == -1)
			return (-1);
		if (child_pid == 0)
		{
			write(STDIN_FILENO, "$ ", 2);
			chars = (getline(&buffer, &buffsize, stdin));
			if (chars == -1)
				return (-1);
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
			execve(token[0], token, NULL);
			perror("Error on Execve");
			return (-1);
		}
		if (child_pid > 0)
			wait(&status);
	}
	return (0);
}
