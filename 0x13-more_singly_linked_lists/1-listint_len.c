#include "lists.h"
#include <stddef.h>
/**
 * listint_len - count the number of elements in a linked listint_t list
 * @h: a const pointer to head of list
 * Return: the number of elements in the list
 */
size_t listint_len(const listint_t *h)
{
	const listint_t *l = h;
	size_t n;

	for (n = 0; l != NULL; n++)
		l = l->next;
	return (n);
}
