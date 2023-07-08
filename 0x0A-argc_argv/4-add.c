#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
/**
 * main - adds positive numbers
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int sum = 0, i = 1, n;
	unsigned long int j;

	while (i < argc)
	{
		j = 0;
		if (isdigit(*argv[i]) || *argv[i] == '-')
			j++;
		while (isdigit(argv[i][j]))
			j++;
		if (j == strlen(argv[i]))
			n = atoi(argv[i]);
		else
		{
			printf("Error\n");
			return (1);
		}
		sum += n;
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
