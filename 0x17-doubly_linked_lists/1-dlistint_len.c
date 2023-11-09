#include "lists.h"

/**
 * dlistint_len - returns the number of elements in a linked dlistint_t list
 * @h: pointer to head node
 * Return: size of linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	const dlistint_t *node;
	size_t size;

	size = 0;
	for (node = h; node; node = node->next)
		size++;
	return (size);
}
