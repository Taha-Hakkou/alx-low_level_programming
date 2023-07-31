#include "lists.h"
/**
 * list_len - count the number of elements in a linked list_t list
 * @h: a const pointer to the head of linked list
 * Return: the number of elements in the linked list
 */
size_t list_len(const list_t *h)
{
	const list_t *l = h;
	size_t i;

	for (i = 0; l != NULL; i++)
		l = l->next;
	return (i);
}
