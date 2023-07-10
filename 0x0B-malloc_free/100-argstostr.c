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
	char *s = NULL;
	int l = 0, i = 0;

	if (ac != 0 && av != NULL)
	{
		while (i < ac)
		{
			l += strlen(av[i]);
			i++;
		}
		s = malloc(l + ac + 1);
		if (s != NULL)
		{
			i = 0;
			while (i < ac)
			{
				memcpy(s, av[i], strlen(av[i]));
				memcpy(s, "\n", 1);
				i++;
			}
			memcpy(s, "", 1);
		}
	}
	return (s);
}
