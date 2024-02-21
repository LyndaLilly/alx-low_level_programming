#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - creates shash table
 * @size: size
 * Return: NULL
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int x;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (x = 0; x < size; x++)
		ht->array[x] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - sets shash table
 * @ht: the hash table
 * @key: hash key
 * @value: the value
 * Return: 0 or 1
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new, *tmp;
	char *eu;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	eu = strdup(value);
	if (eu == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	tmp = ht->shead;
	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			free(tmp->value);
			tmp->value = eu;
			return (1);
		}
		tmp = tmp->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(eu);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(eu);
		free(new);
		return (0);
	}
	new->value = eu;
	new->next = ht->array[index];
	ht->array[index] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		tmp = ht->shead;
		while (tmp->snext != NULL && strcmp(tmp->snext->key, key) < 0)
			tmp = tmp->snext;
		new->sprev = tmp;
		new->snext = tmp->snext;
		if (tmp->snext == NULL)
			ht->stail = new;
		else
			tmp->snext->sprev = new;
		tmp->snext = new;
	}

	return (1);
}

/**
 * shash_table_get - gets shash key
 * @ht: this is hash table
 * @key: The key to add
 * Return: 0 or 1
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *y;
	unsigned long int bx;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	bx = key_index((const unsigned char *)key, ht->size);
	if (bx >= ht->size)
		return (NULL);

	y = ht->shead;
	while (y != NULL && strcmp(y->key, key) != 0)
		y = y->snext;

	return ((y == NULL) ? NULL : y->value);
}

/**
 * shash_table_print - prints shash table
 * @ht: the hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *y;

	if (ht == NULL)
		return;

	y = ht->shead;
	printf("{");
	while (y != NULL)
	{
		printf("'%s': '%s'", y->key, y->value);
		y = y->snext;
		if (y != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints shash table reverse.
 * @ht: this is hash table.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *y;

	if (ht == NULL)
		return;

	y = ht->stail;
	printf("{");
	while (y != NULL)
	{
		printf("'%s': '%s'", y->key, y->value);
		y = y->sprev;
		if (y != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes shash table.
 * @ht: this is hash table
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *y, *pt;

	if (ht == NULL)
		return;

	y = ht->shead;
	while (y)
	{
		pt = y->snext;
		free(y->key);
		free(y->value);
		free(y);
		y = pt;
	}

	free(head->array);
	free(head);
}
