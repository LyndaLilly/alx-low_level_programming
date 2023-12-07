#include "lists.h"

/**
 * insert_dnodeint_at_index - this inserts node at index
 * @h: this is the head of the list
 * @idx: index
 * @n: new node
 * Return: suceess or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *m;
	dlistint_t *head;
	unsigned int i;

	m = NULL;
	if (idx == 0)
		m = add_dnodeint(h, n);
	else
	{
		head = *h;
		i = 1;
		if (head != NULL)
			while (head->prev != NULL)
				head = head->prev;
		while (head != NULL)
		{
			if (i == idx)
			{
				if (head->next == NULL)
					m = add_dnodeint_end(h, n);
				else
				{
					m = malloc(sizeof(dlistint_t));
					if (m!= NULL)
					{
						m->n = n;
						m->next = head->next;
						m->prev = head;
						head->next->prev = m;
						head->next = m;
					}
				}
				break;
			}
			head = head->next;
			i++;
		}
	}

	return (m);
}
