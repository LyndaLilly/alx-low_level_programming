#include "hash_tables.h"

/**
 * hash_table_set - this is the hash table set
 * @ht: this is the hash table
 * @key: A key
 * @value: The value
 * Return: 0 or - 1
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *x;
	char *y;
	unsigned long int ab, p;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	y = strdup(value);
	if (y == NULL)
		return (0);

	ab = key_index((const unsigned char *)key, ht->size);
	for (p = ab; ht->array[p]; p++)
	{
		if (strcmp(ht->array[p]->key, key) == 0)
		{
			free(ht->array[p]->value);
			ht->array[p]->value = y;
			return (1);
		}
	}

	x = malloc(sizeof(hash_node_t));
	if (x == NULL)
	{
		free(y);
		return (0);
	}
	x->key = strdup(key);
	if (x->key == NULL)
	{
		free(x);
		return (0);
	}
	x->value = y;
	x->next = ht->array[ab];
	ht->array[ab] = x;

	return (1);
}
