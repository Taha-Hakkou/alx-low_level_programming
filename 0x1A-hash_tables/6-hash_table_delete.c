#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: hash table to delete
 * Return: Nothing
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp;

	if (!ht)
		return;
	for (i = 0; i < ht->size; i++)
		while (ht->array[i])
		{
			tmp = ht->array[i];
			ht->array[i] = ht->array[i]->next;
			free(tmp->key);
			free(tmp->value);
			free(tmp);
		}
	free(ht->array);
	free(ht);
}
