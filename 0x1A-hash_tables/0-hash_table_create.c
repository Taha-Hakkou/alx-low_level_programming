#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: array size
 * Return: a pointer to the newly created hash table
 *		   or NULL if something went wrong
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(hash_table_t));
	if (ht)
	{
		ht->size = size;
		ht->array = calloc(size, sizeof(hash_node_t *));
		if (ht->array)
			for (i = 0; i < size; i++)
				ht->array[i] = NULL;
		else
		{
			free(ht);
			ht = NULL;
		}
	}
	return (ht);
}
