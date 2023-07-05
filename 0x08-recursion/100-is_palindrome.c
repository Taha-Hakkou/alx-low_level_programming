#include "main.h"

int len_recursion(char *s);
int check_palindrome(char *s, int i, int len);

/**
 * is_palindrome - check if a string is a palindrome
 * @s: string
 *
 * Return: 1 if a string is a palindrome and 0 if not
 */
int is_palindrome(char *s)
{
	if (*s == 0)
		return (1);
	return (check_palindrome(s, 0, len_recursion(s)));
}

/**
 * len_recursion - returns the length of a string
 * @s: string to calculate the length of
 *
 * Return: length of the string
 */
int len_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	return (1 + len_recursion(s + 1));
}

/**
 * check_palindrome - checks the characters recursively for palindrome
 * @s: string to check
 * @i: iterator
 * @len: length of the string
 *
 * Return: 1 if palindrome, 0 if not
 */
int check_palindrome(char *s, int i, int len)
{
	if (*(s + i) != *(s + len - 1))
		return (0);
	if (i >= len)
		return (1);
	return (check_palindrome(s, i + 1, len - 1));
}

