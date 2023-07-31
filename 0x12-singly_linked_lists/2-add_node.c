#include "lists.h"
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: first node of linked list
 * @str: string data of new node
 * Return: the address of the new element, or NULL if it failed
 */
list_t *add_node(list_t **head, const char *str)
{
	unsigned int i = 0;
	list_t *node;

	node = malloc(sizeof(list_t));
	if (node != NULL)
	{
		node->str = strdup(str);
		if (node->str == NULL)
		{
			free(node);
			return (NULL);
		}
		while (node->str[i] != '\0')
			i++;
		node->len = i;
		node->next = *head;
		*head = node;
	}
	return (node);
}
