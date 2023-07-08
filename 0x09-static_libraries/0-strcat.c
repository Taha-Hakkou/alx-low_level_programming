#include "main.h"
/**
 * _strcat - concatenates two strings
 * @dest: destination buffer
 * @src: source buffe
 *
 * Return: a pointer to the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	char *str;

	str = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (str);
}
