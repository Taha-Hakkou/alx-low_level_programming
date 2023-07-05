#include "main.h"
/**
 * is_palindrome - check if a string is a palindrome
 * @s: string
 *
 * Return: 1 if a string is a palindrome and 0 if not
 */
int is_palindrome(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if (*s == s[i - 1])
	{
		s[i - 1] = '\0';
		return (is_palindrome(++s));
	}
	return (0);
}
