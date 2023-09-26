#include <stdlib.h>
#include <stdio.h>
#include "lists.h"
/**
 * free_listint_safe - Frees a listint_t list safely
 * @h: A pointer to a pointer to the head of the list.
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	size_t size = 0;
	int fill;
	listint_t *tmp;

	if (!h || !*h)
		return (0);
	while (*h)
	{
		fill = *h - (*h)->next;
		if (fill > 0)
		{
			tmp = (*h)->next;
			free(*h);
			*h = tmp;
			size++;
		}
		else
		{
			free(*h);
			*h = NULL;
			size++;
			break;
		}
	}
	*h = NULL;
	return (size);
}
