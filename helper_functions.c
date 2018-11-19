#include "bengie.h"

/**
 * _strcmp - Compares 2 strings
 * @s1: 1st string
 * @s2: 2nd string
 *
 * Return: Value = 0 if s1 = s2, value < 0 if s1 < s2, or value > 0 if s1 > s2
 */

int _strcmp(char *s1, char *s2)

{
	int index;

	index = 0;
	while (s1[index] != '\0' || s2[index] != '\0')
	{
		if (s1[index] == s2[index])
		{
			index++;
			continue;
		}
		else
		{
			return (s1[index] - s2[index]);
		}
	}
	return (0);
}
