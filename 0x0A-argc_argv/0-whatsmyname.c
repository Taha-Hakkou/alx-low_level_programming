#include <stdio.h>
#include "main.h"
/**
 * main - prints the program's name, followed by a newline
 * @argc: arguments count
 * @argv: arguments vector
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", *argv);
	return (0);
}
