#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
* add_node_end - this adds a new node
* @head: double pointer
* @str: string to put in the new node
* Return: address
*/
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *add;
	list_t *mp = *head;
	int len = 0;

	while (str[len])
		len++;
	add = malloc(sizeof(list_t));
	if (!add)
		return (NULL);

	add->str = strdup(str);
	add->len = len;
	add->next = NULL;
	if (*head == NULL)
	{
		*head = add;
		return (add);
	}
	while (mp->next)
		mp = mp->next;
	mp->next = add;
	return (add);
}
