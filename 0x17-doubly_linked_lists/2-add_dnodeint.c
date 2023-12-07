#include "lists.h"

/**
 * add_dnodeint - this is add linked list
 * @head: this is is head of the list
 * @n: thius is no of linked list
 * Return: address
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *pu;
	dlistint_t *h;

	pu = malloc(sizeof(dlistint_t));
	if (pu == NULL)
		return (NULL);

	pu->n = n;
	pu->prev = NULL;
	h = *head;

	if (h != NULL)
	{
		while (h->prev != NULL)
			h = h->prev;
	}

	pu->next = h;

	if (h != NULL)
		h->prev = pu;

	*head = pu;

	return (pu);
}
