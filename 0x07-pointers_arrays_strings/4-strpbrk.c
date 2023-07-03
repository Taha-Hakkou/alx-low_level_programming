#include "main.h"
#include <stddef.h>
/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string
 * @accept: acceptable bytes
 *
 * Description: locates the first occurrence in the string s
 *	   of any of the bytes in the string accept
 *
 * Return: a pointer to the byte in s that matches one of
 *	   the bytes in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	int i, j, found;

	found = 0;
	i = 0;
	while (!found && s[i] != '\0')
	{
		j = 0;
		while (accept[j] != s[i] && accept[j] != '\0')
			j++;
		if (accept[j] == s[i])
		{
			found = 1;
			break;
		}
		i++;
	}
	if (s[i] == '\0')
		return (NULL);
	else
		return (s + i);
}
