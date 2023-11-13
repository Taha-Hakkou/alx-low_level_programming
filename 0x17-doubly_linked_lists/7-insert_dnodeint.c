#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: head of the list
 * @idx: index of the new node
 * @n: value of the new node
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *tmp;
	unsigned int i;

	node = NULL;
	if (idx == 0)
		node = add_dnodeint(h, n);
	else
	{
		tmp = *h;
		i = 1;
		if (tmp)
			while (tmp->prev)
				tmp = tmp->prev;
		while (tmp)
		{
			if (i == idx)
			{
				if (tmp->next == NULL)
					node = add_dnodeint_end(h, n);
				else
				{
					node = malloc(sizeof(dlistint_t));
					if (node)
					{
						node->n = n;
						node->next = tmp->next;
						node->prev = tmp;
						tmp->next->prev = node;
						tmp->next = node;
					}
				}
				break;
			}
			tmp = tmp->next;
			i++;
		}
	}
	return (node);
}
