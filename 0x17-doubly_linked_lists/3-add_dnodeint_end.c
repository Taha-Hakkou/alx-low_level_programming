#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to pointer to head node
 * @n: data of new node
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *tmp;

	node = malloc(sizeof(dlistint_t));
	if (node)
	{
		node->n = n;
		if (!(*head))
		{
			node->prev = *head;
			*head = node;
		}
		else
		{
			for (tmp = *head; tmp->next; tmp = tmp->next)
				continue;
			node->prev = tmp;
			tmp->next = node;
		}
		node->next = NULL;
		return (node);
	}
	else
		return (NULL);
}
