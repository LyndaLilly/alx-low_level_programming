#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: linked list to search for
 * Return: The address of the node where the loop starts, or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *start = head;
	listint_t *stop = head;

	if (!head)
		return (NULL);
	while (start && stop && stop->next)
	{
		stop = stop->next->next;
		start = start->next;
		if (stop == start)
		{
			start = head;
			while (start != stop)
			{
				start = start->next;
				stop = stop->next;
			}
			return (stop);
		}
	}
	return (NULL);
}
