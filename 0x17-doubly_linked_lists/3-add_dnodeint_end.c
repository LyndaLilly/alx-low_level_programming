#include "lists.h"

/**
 * add_dnodeint_end - add node to the end of list
 * @head: this is the head of the list
 * @n: the no of list
 * Return: the address
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *h;
	dlistint_t *te;

	te = malloc(sizeof(dlistint_t));
	if (te == NULL)
		return (NULL);

	te->n = n;
	te->next = NULL;

	h = *head;

	if (h != NULL)
	{
		while (h->next != NULL)
			h = h->next;
		h->next = te;
	}
	else
	{
		*head = te;
	}

	te->prev = h;

	return (te);
}
