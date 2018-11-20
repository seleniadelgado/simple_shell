#include "bengie.h"

/**
 * matchpath - a function that finds path in the environment.
 * @s1: a pointer to the first string/name
 * @s2: a pointer to the second string/path
 *
 * Return: 0 if successful or -1 if failed.
 */

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

/**
 * _getenv - a function that finds the current environment variable.
 * @name: the name of the environment varaible to get.
 *
 * Return: the string of the environmental variable
 */
char *_getenv(const char *name)
{
	int index;
	/*int length;*/

	/*length = strlen (name);*/

	for (index = 0; environ[index]; index++)
	{
		if (matchpath(name, environ[index]) == 0)
		{
			return (environ[index]);
		}
	}
	return (NULL);
}

/**
 * print_env - a function that prints out the current environment variable.
 *
 * Return: nothing
 */
void print_env(void)
{
	char *string;
	char *name = "PATH";
	int i;

	string = _getenv(name);

	for (i = 0; string[i]; i++)
		;
	write(STDIN_FILENO, string, i);
	write(STDIN_FILENO, "\n", 1);
}

/**
 * delim_path - a function that delimits the path.
 *
 * Return: nothing
 */
void delim_path(void)
{
	char *string;
	char *name = "PATH";
	int i;
	char *trent[1024];
	int k = 0;

	string = _getenv(name);

	for (i = 0; string[i]; i++)
		;
	trent[k] = strtok(string, ":");

	while (trent[k] != NULL)
	{
		k++;
		trent[k] = strtok(NULL, ":");
	}
	k = 0;
	while (trent[k] != NULL)
	{
		printf("trent = %s", trent[k]);
		k++;
	}
}
