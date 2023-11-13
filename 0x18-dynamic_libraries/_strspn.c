#include "main.h"
/**
 * _strspn - gets the length of a prefix substring
 * @s: string
 * @accept: acceptable bytes
 *
 * Return: the number of bytes in the initial segmen
 *	   of s which consist only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	int j, found;

	found = 0;
	i = 0;
	while (found && s[i] != '\0')
	{
		j = 0;
		while (accept[j] != s[i] && accept[j] != '\0')
			j++;
		if (s[i] == accept[j])
			found = 1;
		else
		{
			found = 0;
			break;
		}
		i++;
	}
	return (i);
}
