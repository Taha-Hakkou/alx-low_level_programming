#include "search_algos.h"
/**
 * linear_skip - searches for a value in a sorted skip list of integers
 * @list: pointer to head of the skip list to search in
 * @value: value to search for
 * Return: pointer to first node where value is located,
 *	   or NULL is head is NULL or value not found
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *node, *tmp, *xnode;

	if (list == NULL)
		return (NULL);
	node = list;
	while (node->express && node->express->n < value)
	{
		node = node->express;
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	}
	if (node->express)
	{
		tmp = node->express;
		printf("Value checked at index [%ld] = [%d]\n", tmp->index, tmp->n);
	}
	else
	{
		tmp = node;
		while (tmp->next)
			tmp = tmp->next;
	}
	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, tmp->index);
	xnode = node;
	while (xnode != tmp && xnode != node->express)
	{
		printf("Value checked at index [%ld] = [%d]\n", xnode->index, xnode->n);
		if (xnode->n == value)
			return (xnode);
		xnode = xnode->next;
	}
	return (NULL);
}
