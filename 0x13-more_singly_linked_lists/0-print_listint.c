#include "lists.h"
#include <stdio.h>
#include <stddef.h>
/**
 * print_listint - prints all the elements of a listint_t list
 * @h: a const pointer to the head of list
 * Return: the number of nodes
 */
size_t print_listint(const listint_t *h)
{
	const listint_t *l = h;
	size_t n;

	for (n = 0; l != NULL; n++)
	{
		printf("%d\n", l->n);
		l = l->next;
	}
	return (n);
}
