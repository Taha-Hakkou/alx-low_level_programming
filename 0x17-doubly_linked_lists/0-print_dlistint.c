#include "lists.h"

/**
 * print_dlistint - prints all the elements of a dlistint_t list
 * @h: pointer to head node
 * Return: the number of nodes
 */
size_t print_dlistint(const dlistint_t *h)
{
	const dlistint_t *node;
	size_t size;

	size = 0;
	for (node = h; node; node = node->next)
	{
		printf("%d\n", node->n);
		size++;
	}
	return (size);
}
