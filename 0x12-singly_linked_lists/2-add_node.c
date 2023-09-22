#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
* add_node - This will add a new node at the beginning of a linked list
* @head: double pointer
* @str: new string to add in the node
* Return: the address
*/
list_t *add_node(list_t **head, const char *str)
{
list_t *current;
unsigned int len = 0;

while (str[len])
	len++;

current = malloc(sizeof(list_t));
if (!current)
	return (NULL);
current->str = strdup(str);
current->len = len;
current->next = (*head);
(*head) = current;
return (*head);
}
