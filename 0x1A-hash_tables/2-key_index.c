#include "hash_tables.h"

/**
 * key_index - gives the index of a key
 *			uses the 'hash_djb2' function
 * @key: key
 * @size: the hash table array size
 * Return: index at which the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}

/**
 * shash_table_set - adds a newly allocated node
 *					or overwrites one with existing key
 *					__sorted on ASCII value__
 * @ht: hash table to insert in
 * @key: the key (non-empty string)
 * @value: value associated with key
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node, *tmp;
	unsigned long int index;

	if (!ht || !key || !(*key) || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size); /* ht insertion */
	tmp = ht->array[index];
	while (tmp && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (tmp)
	{
		free(tmp->value);
		tmp->value = strdup(value);
		return (1);
	}
	node = malloc(sizeof(shash_node_t));
	if (node) /* node creation */
	{
		node->key = strdup(key);
		node->value = strdup(value);
		node->next = ht->array[index];
		ht->array[index] = node;
	} else
		return (0);
	insert(ht, node);
	return (1);
}

/**
 * insert - inserts in order
 * @ht: hash table
 * @node: node to insert
 * Return: Nothing
 */
void insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *tmp;

	if (ht->shead == NULL) /* sorted insertion */
	{
		node->sprev = NULL;
		node->snext = NULL;
		ht->shead = node;
		ht->stail = node;
	} else
	{
		tmp = ht->shead;
		while (tmp && strcmp(tmp->key, node->key) < 0)
			tmp = tmp->snext;
		if (tmp == ht->shead) /* node => shead */
		{
			node->sprev = NULL;
			node->snext = tmp;
			tmp->sprev = node;
			ht->shead = node;
		} else if (tmp == NULL) /* node => stail */
		{
			node->sprev = ht->stail;
			node->snext = NULL;
			ht->stail->snext = node;
			ht->stail = node;
		} else
		{
			node->sprev = tmp->sprev;
			node->snext = tmp;
			tmp->sprev->snext = node;
			tmp->sprev = node;
		}
	}
}
