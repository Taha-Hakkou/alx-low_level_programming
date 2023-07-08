#include "main.h"
#include <stddef.h>
/**
 * _strstr - locates a substring
 * @haystack: string
 * @needle: substring
 *
 * Description: finds the first occurrence of the substring needle
 *	   in the string haystack. The terminating null bytes (\0)
 *	   are not compared
 *
 * Return: a pointer to the beginning of the located substring,
 *	   or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
	int i, j, found;

	found = 0;
	i = 0;
	while (!found && haystack[i] != '\0')
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
		{
			found = 1;
			break;
		}
		i++;
	}
	if (haystack[i] == '\0')
		return (NULL);
	else
		return (haystack + i);
}
