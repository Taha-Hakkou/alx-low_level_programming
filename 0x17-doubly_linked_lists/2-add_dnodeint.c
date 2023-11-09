#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to pointer to head node
 * @n: data of the new node
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (node)
	{
		node->n = n;
		node->prev = NULL;
		node->next = *head;
		*head = node;
		return (node);
	}
	else
		return (NULL);

}
