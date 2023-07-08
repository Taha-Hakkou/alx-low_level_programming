#include "main.h"
/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 if equal, >0 if s1 is greater, <0 if s1 is lower
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	i = -1;
	do {
		i++;
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
	} while (*(s1 + i) != '\0' && *(s2 + i) != '\0');
	return (0);
}
