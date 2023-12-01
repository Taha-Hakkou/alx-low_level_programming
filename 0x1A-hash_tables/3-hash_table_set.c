#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 *						In case of collision, add the new node at the beginning of the list
 * @ht: the hash table to add in
 * @key: key (not empty string)
 * @value: value associated with the key (must be duplicated)
 *			can be empty string
 * Return: 1 on success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *tmp;

	if (!ht || !key || !(*key) || !value)
		return (0);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp && strcmp(tmp->key, key) != 0)
		tmp = tmp->next;
	if (tmp)
	{
		free(tmp->value);
		tmp->value = strdup(value);
		return (1);
	}
	tmp = malloc(sizeof(shash_node_t));
	if (tmp) /* node creation */
	{
		tmp->key = strdup(key);
		tmp->value = strdup(value);
		tmp->next = ht->array[index];
		ht->array[index] = tmp;
	} else
		return (0);
	return (1);
}
