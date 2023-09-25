#include <stdlib.h>
#include "lists.h"
void free_listint2(listint_t **head)
{
	listint_t *current = *head;
	listint_t *temp;

	while (current != NULL)
	{
		temp = current;
		current = current->next;
		free(temp);
	}
	*head = NULL;
}
