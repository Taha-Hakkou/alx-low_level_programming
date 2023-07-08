#include <stdio.h>
#include <stdlib.h>
/**
 * main - prints the minimum number of coins
 *	  to make change for an amount of money
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0
 */
int main(int argc, char *argv[])
{
	int j, n, coins;
	int coin[] = {25, 10, 5, 2, 1};

	n = 0;
	coins = 0;
	if (argc == 2)
	{
		n = atoi(argv[1]);
		j = 0;
		while (n > 0)
		{
			coins += (n / coin[j]);
			n %= coin[j];
			j++;
		}
		printf("%d\n", coins);
	}
	else
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}
