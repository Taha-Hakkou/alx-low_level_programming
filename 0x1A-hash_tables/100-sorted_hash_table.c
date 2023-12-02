#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the sorted hash table's array
 * Return: a pointer to newly created sorted hash table
 *		   or NULL if something went wrong
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht)
	{
		ht->size = size;
		ht->shead = NULL;
		ht->stail = NULL;
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

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table to get from
 * @key: looked-for key
 * Return: value associated with element if found, NULL otherwise
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *tmp;

	if (!ht || !key)
		return (NULL);
	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->array[index];
	while (tmp)
	{
		if (!strcmp(tmp->key, key))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: hash table to print
 * Return: Nothing
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht)
		return;
	putchar('{');
	for (tmp = ht->shead; tmp; tmp = tmp->snext)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (tmp != ht->stail)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse
 * @ht: hash table to print
 * Return: Nothing
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht)
		return;
	putchar('{');
	for (tmp = ht->stail; tmp; tmp = tmp->sprev)
	{
		printf("'%s': '%s'", tmp->key, tmp->value);
		if (tmp != ht->shead)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: hash table to delete
 * Return: Nothing
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht)
		return;
	for (tmp = ht->shead; tmp->snext;)
	{
		tmp = tmp->snext;
		free(tmp->sprev);
	}
	free(tmp);
	free(ht->array);
	free(ht);
}
