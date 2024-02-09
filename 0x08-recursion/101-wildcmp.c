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
	char *str1 = s1, *str2 = s2;

	while (*str1 != '\0' && *str2 != '\0' && *str2 != '*')
		if (*(str1++) != *(str2++))
			return (0);
	if (*str1 == '\0')
	{
		while (*str2 != '\0')
			if (*(str2++) != '*')
				return (0);
		return (1);
	}
	if (*str2 == '\0')
	{
		if (*str1 == '\0')
			return (1);
		return (0);
	}
	do {
		if (wildcmp(str1, str2 + 1))
			return (1);
	} while (*(str1++) != '\0');
	return (0);
}
