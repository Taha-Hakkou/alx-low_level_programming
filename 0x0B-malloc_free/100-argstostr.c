#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
/**
 * argstostr - concatenates all the arguments of your program
 *		separated by newline
 * @ac: arguments count
 * @av: arguments vector
 *
 * Return: a pointer to a new string,
 *	   or NULL if it fails, ac == 0, or av == NULL
 */
char *argstostr(int ac, char **av)
{
	int i, n, r = 0, l = 0;
	char *s;

	if (ac == 0 || av == NULL)
		return (NULL);

	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
			l++;
	}

	l += ac;
	s = malloc(sizeof(char) * l + 1);
	if (s == NULL)
		return (NULL);
	for (i = 0; i < ac; i++)
	{
		for (n = 0; av[i][n]; n++)
		{
			s[r] = av[i][n];
			r++;
		}
		if (s[r] == '\0')
			s[r++] = '\n';
	}
	return (s);
}
