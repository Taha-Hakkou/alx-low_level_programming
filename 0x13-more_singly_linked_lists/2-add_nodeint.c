#include "lists.h"
#include <stddef.h>
#include <stdlib.h>
/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: a pointer to a pointer to the first node
 * @n: integer data of the node
 * Return: the address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *node;

	node = malloc(sizeof(*node));
	if (node != NULL)
	{
		node->n = n;
		node->next = *head;
		*head = node;
	}
	return (node);
}
