#include "lists.h"

/**
 * sum_dlistint - returns sum of all the data (n) of a dlistint_t linked list
 * @head: pointer to head node
 * Return: if the list is empty, return 0
 */
int sum_dlistint(dlistint_t *head)
{
	dlistint_t *node;
	int sum;

	sum = 0;
	for (node = head; node; node = node->next)
		sum += node->n;
	return (sum);
}
