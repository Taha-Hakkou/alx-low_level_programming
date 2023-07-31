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
	listint_t *l = *head;
	unsigned int i;

	node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->n = n;
		for (i = 0; i < idx - 1; i++)
		{
			if (l->next != NULL)
				l = l->next;
			else
			{
				free(node);
				return (NULL);
			}
		}
		node->next = l->next;
		l->next = node;
	}
	return (node);
}
