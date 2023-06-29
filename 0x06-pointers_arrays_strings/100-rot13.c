#include "main.h"
/**
 * rot13 - encodes a string using rot13
 * @s: decoded string
 *
 * Return: encoded string
 */
char *rot13(char *s)
{
	int i;
	int j;
	char regular[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; j < 52; j++)
		{
			if (s[i] == regular[j])
			{
				s[i] = rot13[j];
				break;
			}
		}
	}
	return (s);
}
