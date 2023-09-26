#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * delete_nodeint_at_index -  Function to delete a node at a specific index
 * @head: pointer to header list
 * @index: index of the node to delete
 * Return: 1 (Success), or -1 (Fail)
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current = *head;
	listint_t *prev = NULL;
	unsigned int x = 0;

	if (*head == NULL)
		return (-1);
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		return (1);
	}
	while (x < index - 1)
	{
		if (!current || !(current->next))
			return (-1);
		current = current->next;
		x++;
	}
	prev = current->next;
	current->next = prev->next;
	free(prev);
	return (1);
}
