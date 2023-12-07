#include "lists.h"

/**
 * sum_dlistint - sums a linked list
 * @head: this is the head of the lis
 * Return: data
 */
int sum_dlistint(dlistint_t *head)
{
	int x;

	x = 0;

	if (head != NULL)
	{
		while (head->prev != NULL)
			head = head->prev;

		while (head != NULL)
		{
			x += head->n;
			head = head->next;
		}
	}

	return (x);
}
