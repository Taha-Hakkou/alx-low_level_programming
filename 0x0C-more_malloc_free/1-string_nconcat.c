#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * string_nconcat - concatenates 2 strings
 * @s1: first string
 * @s2: second string
 * @n: number of bytes to copy from s2
 *
 * Return: a pointer to newly allocated string,
 *	   and NULL if allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	if (n >= strlen(s2))
		n = strlen(s2);
	s = malloc(strlen(s1) + n + 1);
	if (s != NULL)
	{
		memcpy(s, s1, strlen(s1));
		memcpy(s + strlen(s1), s2, n);
		memcpy(s + strlen(s1) + n, "", 1);
	}
	return (s);
}
