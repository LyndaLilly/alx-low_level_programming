#include "search_algos.h"

/**
 * linear_skip - this skips linear
 * @list: this is the list
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *ptr;

	if (list == NULL)
		return (NULL);

	ptr = list;

	do {
		list = ptr;
		ptr = ptr->express;
		printf("Value checked at index ");
		printf("[%d] = [%d]\n", (int)ptr->index, ptr->n);
	} while (ptr->express && ptr->n < value);

	if (ptr->express == NULL)
	{
		list = ptr;
		while (ptr->next)
			ptr = ptr->next;
	}

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)list->index, (int)ptr->index);

	while (list != ptr->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)list->index, list->n);
		if (list->n == value)
			return (list);
		list = list->next;
	}

	return (NULL);
}
