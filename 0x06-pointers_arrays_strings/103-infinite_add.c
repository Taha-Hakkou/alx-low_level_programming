#include "main.h"
/**
 * rev_string - reverse array
 * @n: integer params
 */
void rev_string(char *n)
{
	int i = 0;
	int j = 0;
	char tmp;

	while (*(n + i) != '\0')
		i++;
	i--;
	for (j = 0; j < i; j++, i--)
	{
		tmp = *(n + j);
		*(n + j) = *(n + i);
		*(n + i) = tmp;
	}
}
/**
 * infinite_add - adds two numbers
 * @n1: first number
 * @n2: second number
 * @r: the buffer that the function will use to store the result
 * @size_r: the buffer size
 *
 * Return: a pointer to the result
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int ovf = 0, i = 0, j = 0, digits = 0;
	int v1 = 0, v2 = 0, sum = 0;

	while (*(n1 + i) != '\0')
		i++;
	while (*(n2 + j) != '\0')
		j++;
	i--;
	j--;
	if (j >= size_r || i >= size_r)
		return (0);
	while (j >= 0 || i >= 0 || ovf == 1)
	{
		if (i < 0)
			v1 = 0;
		else
			v1 = *(n1 + i) - '0';
		if (j < 0)
			v2 = 0;
		else
			v2 = *(n2 + j) - '0';
		sum = v1 + v2 + ovf;
		if (sum >= 10)
			ovf = 1;
		else
			ovf = 0;
		if (digits >= (size_r - 1))
			return (0);
		*(r + digits) = (sum % 10) + '0';
		digits++;
		j--;
		i--;
	}
	if (digits == size_r)
		return (0);
	*(r + digits) = '\0';
	rev_string(r);
	return (r);
}
