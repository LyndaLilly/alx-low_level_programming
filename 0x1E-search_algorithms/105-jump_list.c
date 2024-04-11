#include "search_algos.h"
#include <math.h>

/**
 * jump_list - this is the jump list
 * @list: this is the list
 * @size: this is the size
 * @value: this is the value
 * Return: Always EXIT_SUCCESS
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t res, mx, yt;
	listint_t *tx;

	if (list == NULL || size == 0)
		return (NULL);

	yt = (size_t)sqrt((double)size);
	res = 0;
	mx = 0;

	do {
		tx = list;
		mx++;
		res = mx * yt;

		while (list->next && list->index < res)
			list = list->next;

		if (list->next == NULL && res != list->index)
			res = list->index;

		printf("Value checked at index [%d] = [%d]\n", (int)res, list->n);

	} while (res < size && list->next && list->n < value);

	printf("Value found between indexes ");
	printf("[%d] and [%d]\n", (int)tx->index, (int)list->index);

	for (; tx && tx->index <= list->index; tx = tx->next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)tx->index, tx->n);
		if (tx->n == value)
			return (tx);
	}

	return (NULL);
}
