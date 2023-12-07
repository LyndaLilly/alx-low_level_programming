#include "lists.h"

/**
 * dlistint_len - this is length of linked list
 * @h: this is headf
 * Return: nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	int xc;

	xc = 0;

	if (h == NULL)
		return (xc);
	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		xc++;
		h = h->next;
	}

	return (xc);
}
