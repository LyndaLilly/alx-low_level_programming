#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - this si the shash table
 * @size: size of the shash table
 * Return: NULL or pointer
 */

shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int rt;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (rt = 0; rt < size; rt++)
		ht->array[rt] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - sets shash table
 * @ht: this is hash table
 * @key: The key to add
 * @value: value of key
 * Return: 0 or 1
 */

int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *xt, *pt;
	char *ou;
	unsigned long int lt;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	ou = strdup(value);
	if (ou == NULL)
		return (0);

	lt = key_index((const unsigned char *)key, ht->size);
	pt = ht->shead;
	while (pt)
	{
		if (strcmp(pt->key, key) == 0)
		{
			free(pt->value);
			pt->value = ou;
			return (1);
		}
		pt = pt->snext;
	}

	xt = malloc(sizeof(shash_node_t));
	if (xt == NULL)
	{
		free(ou);
		return (0);
	}
	xt->key = strdup(key);
	if (xt->key == NULL)
	{
		free(ou);
		free(xt);
		return (0);
	}
	xt->value = ou;
	xt->next = ht->array[lt];
	ht->array[lt] = xt;

	if (ht->shead == NULL)
	{
		xt->sprev = NULL;
		xt->snext = NULL;
		ht->shead = xt;
		ht->stail = xt;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		xt->sprev = NULL;
		xt->snext = ht->shead;
		ht->shead->sprev = xt;
		ht->shead = xt;
	}
	else
	{
		pt = ht->shead;
		while (pt->snext != NULL && strcmp(pt->snext->key, key) < 0)
			pt = pt->snext;
		xt->sprev = pt;
		xt->snext = pt->snext;
		if (pt->snext == NULL)
			ht->stail = xt;
		else
			pt->snext->sprev = xt;
		pt->snext = xt;
	}

	return (1);
}

/**
 * shash_table_get - sets shash table
 * @ht: this is hash table
 * @key: The key to add
 * @value: value of key
 * Return: 0 or 1
 */

char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *qe;
	unsigned long int lt;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	lt = key_index((const unsigned char *)key, ht->size);
	if (lt >= ht->size)
		return (NULL);

	qe = ht->shead;
	while (qe != NULL && strcmp(qe->key, key) != 0)
		qe = qe->snext;

	return ((qe == NULL) ? NULL : qe->value);
}

/**
 * shash_table_print - prints a sorted hash table in order.
 * @ht: a pointer to the sorted hash table.
 */

void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *qe;

	if (ht == NULL)
		return;

	qe = ht->shead;
	printf("{");
	while (qe != NULL)
	{
		printf("'%s': '%s'", qe->key, qe->value);
		qe = qe->snext;
		if (qe != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order.
 * @ht: a pointer to the sorted hash table to print.
 */

void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *qe;

	if (ht == NULL)
		return;

	qe = ht->stail;
	printf("{");
	while (qe != NULL)
	{
		printf("'%s': '%s'", qe->key, qe->value);
		qe = qe->sprev;
		if (qe != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table.
 * @ht: a pointer to the sorted hash table.
 */

void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head = ht;
	shash_node_t *qe, *pt;

	if (ht == NULL)
		return;

	qe = ht->shead;
	while (qe)
	{
		pt = qe->snext;
		free(qe->key);
		free(qe->value);
		free(qe);
		qe = pt;
	}

	free(head->array);
	free(head);
}
