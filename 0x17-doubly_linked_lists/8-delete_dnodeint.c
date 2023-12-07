#include "lists.h"

/**
 * delete_dnodeint_at_index - this deletes the node at index o
 * @head: this is the head of the list
 * @index: index =
 * Return: 1 or -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *x;
	dlistint_t *y;
	unsigned int i;

	x = *head;

	if (x != NULL)
		while (x->prev != NULL)
			x = x->prev;

	i = 0;

	while (x != NULL)
	{
		if (i == index)
		{
			if (i == 0)
			{
				*head = x->next;
				if (*head != NULL)
					(*head)->prev = NULL;
			}
			else
			{
				y->next = x->next;

				if (x->next != NULL)
					x->next->prev = y;
			}

			free(x);
			return (1);
		}
		y = x;
		x = x->next;
		i++;
	}

	return (-1);
}
