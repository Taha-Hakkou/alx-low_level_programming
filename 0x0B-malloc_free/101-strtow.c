#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "main.h"
/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: a pointer to an array of strings (words)
 */
char **strtow(char *str)
{
	char **words = NULL;
	char *word;
	int i, j, k;

	if (str != NULL && *str != '\0')
	{
		words = malloc(strlen(str));
		i = 0;
		k = 0;
		if (words != NULL)
		{
			while (str[i] != '\0')
			{
				word = NULL;
				j = 0;
				while (str[i] != ' ' && str[i] != '\0')
				{
					word[j] = str[i];
					i++;
					j++;
				}
				word[j] = '\0';
				words[k] = word;
			}
		}
	}
	return (words);
}
