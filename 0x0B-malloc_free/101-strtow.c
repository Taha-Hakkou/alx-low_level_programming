#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "main.h"

/**
 * wcount - helper function to count the number of words in a string
 * @s: string to evaluate
 * Return: number of words
 */
int wcount(char *s)
{
	int flag, c, w;

	flag = 0;
	w = 0;
	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == ' ')
			flag = 0;
		else if (flag == 0)
		{
			flag = 1;
			w++;
		}
	}
	return (w);
}

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words, *tmp;
	int i, k = 0, len = 0, wordc, c = 0, start, end;

	while (*(str + len))
		len++;
	wordc = wcount(str);
	if (wordc == 0)
		return (NULL);

	words = (char **) malloc(sizeof(char *) * (wordc + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		if (str[i] == ' ' || str[i] == '\0')
		{
			if (c)
			{
				end = i;
				tmp = (char *) malloc(sizeof(char) * (c + 1));
				if (tmp == NULL)
					return (NULL);
				while (start < end)
					*tmp++ = str[start++];
				*tmp = '\0';
				words[k] = tmp - c;
				k++;
				c = 0;
			}
		}
		else if (c++ == 0)
			start = i;
	}

	words[k] = NULL;

	return (words);
}
