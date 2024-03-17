#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: a pointer to a pointer to the head of linked list
 * @idx: index of the list where the new node should be added
 * @n: integer data of new node
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node;
	listint_t *tmp = *head;
	unsigned int i;

	if (idx == 0)
	{
		node = malloc(sizeof(*node));
		if (node)
		{
			node->n = n;
			node->next = tmp;
			*head = node;
		}
	}
	else
	{
		if (tmp == NULL)
			return (NULL);
		for (i = 0; i < idx - 1; i++)
		{
			if (tmp->next)
				tmp = tmp->next;
			else
				return (NULL);
		}
		node = malloc(sizeof(*node));
		if (node)
		{
			node->n = n;
			node->next = tmp->next;
			tmp->next = node;
		}
	}
	return (node);
}
