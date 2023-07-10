#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "main.h"
/**
 * _strdup - allocates space in memory,
 *	     and copy the value of string
 * @str: string
 *
 * Return: a pointer to a new string which is a duplicate of the string str
 *	   NULL if str = NULL or memory is insufficient
 */
char *_strdup(char *str)
{
	char *p = NULL;

	if (str != NULL)
	{
		p = malloc(strlen(str) + 1);
		if (p == NULL)
			return (p);
		memcpy(p, str, strlen(str) + 1);
	}
	return (p);
}
