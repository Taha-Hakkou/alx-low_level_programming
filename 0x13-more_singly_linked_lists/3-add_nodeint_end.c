#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: a pointer to a pointer to the first node
 * @n: integer data of the new node
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node, *l;

	node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->n = n;
		node->next = NULL;
		if (*head == NULL)
			*head = node;
		else if ((*head)->next == NULL)
			(*head)->next = node;
		else
		{
			l = *head;
			while (l->next != NULL)
				l = l->next;
			l->next = node;
		}
	}
	return (node);
}
