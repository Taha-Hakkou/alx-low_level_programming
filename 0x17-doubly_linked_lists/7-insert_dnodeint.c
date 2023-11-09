#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to pointer to head node
 * @idx: index of list where the new node should be added. Index starts at 0
 * @n: data of new node
 * Return:	the address of the new node, or NULL if it failed
 *			if it is not possible to add the new node at index idx,
 *			do not add the new node and return NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *tmp;
	unsigned int i;

	if (!idx)
		return (add_dnodeint(h, n));
	i = 1;
	for (tmp = *h; tmp->next; tmp = tmp->next)
	{
		if (i == idx)
		{
			node = malloc(sizeof(dlistint_t));
			if (!node)
				return (NULL);
			node->n = n;
			node->prev = tmp;
			node->next = tmp->next;
			tmp->next = node;
			tmp->next->prev = node;
			return (node);
		}
		i++;
	}
	if (i == idx)
		return (add_dnodeint_end(h, n));
	else
		return (NULL);
}
