#include <stdlib.h>
#include "lists.h"
/**
* free_list - frees a linked list
* @head: list_t list to be freed
*/
void free_list(list_t *head)
{
	list_t *current = head;

	while (current != NULL)
	{
		list_t *temp = current;

		current = current->next;
		free(temp);
	}
}
