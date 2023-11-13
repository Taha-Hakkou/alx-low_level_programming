#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: head of the list
 * @n: value of the element
 * Return: the address of the new element
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node, *tmp;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;
	node->prev = NULL;
	tmp = *head;
	if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
	}
	node->next = tmp;
	if (tmp)
		tmp->prev = node;
	*head = node;
	return (node);
}
