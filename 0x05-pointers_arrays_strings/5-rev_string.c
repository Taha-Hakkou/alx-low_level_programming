#include "main.h"
/**
 * rev_string - reverses a string
 * @s: a string to string to be reversed
 */
void rev_string(char *s)
{
	int l, i;
	char *p, tmp;

	p = s;
	while (*p != '\0')
		p++;
	l = p - s;
	i = 0;
	while (i < (l / 2))
	{
		tmp = *(s + i);
		*(s + i) = *(s + l - i - 1);
		*(s + l - i - 1) = tmp;
		i++;
	}
}
