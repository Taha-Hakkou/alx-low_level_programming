#include "main.h"
/**
 * _strncat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffer
 * @n: max length of src to copy
 *
 * Return: a pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *str;
	int i;

	str = dest;
	while (*dest != '\0')
		dest++;
	i = 0;
	while (*src != '\0' && i < n)
	{
		*dest = *src;
		src++;
		dest++;
		i++;
	}
	*dest = '\0';
	return (str);
}
