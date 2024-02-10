#include "main.h"
#include <stdio.h>
/**
 * wildcmp - compares 2 strings
 * @s1: first string
 * @s2: second string
 *
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
	{
		if (*s2 == '\0')
			return (1);
		else if (*s2 == '*')
			return (wildcmp(s1, s2 + 1));
		else
			return (0);
	}
	else
	{
		if (*s2 == '\0')
			return (0);
		else if (*s2 == '*')
			return (wildcmp(s1, s2 + 1) || wildcmp(s1 + 1, s2));
		else if (*s2 == *s1)
			return (wildcmp(s1 + 1, s2 + 1));
		else
			return (0);
	}
}
