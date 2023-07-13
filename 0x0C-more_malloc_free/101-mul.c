#include <stdio.h>
#include <stdlib.h>
/**
 * main - multiplies 2 args
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	char *n1, *n2;
	char *mul;
	if (argc == 3)
	{
		n1 = malloc(strlen(argv[1]) * sizeof(*n1));
		n2 = malloc(strlen(argv[2]) * sizeof(*n2));
		mul = malloc((strlen(argv[1]) + strlen(argv[2])) * sizeof(*mul);
		if (n1 != NULL && n2 != NULL && mul != NULL)
		{
			for (i = 0; i < strlen(argv[2]); i++)
			{
				for (j = 0; j < strlen(argv[1]); j++)
				{
					mul[j] = (argv[1][j] - '0') * (argv[2][i] - '0')
				}
			}
			printf("%s\n", mul);
			return (0);
		}
		else
		{
			printf("Error\n");
			exit(98);
		}
	}
	else
	{
		printf("Error\n");
		exit(98);
	}
}
