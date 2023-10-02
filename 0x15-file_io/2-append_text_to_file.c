#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * append_text_to_file - Appends text at the end of a file.
 * @filename:  is the name of the file
 * @text_content:  is the NULL terminated string to add at the end of the file
 * Return: 1 on success and -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int opened, weight, lengths = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (lengths = 0; text_content[lengths];)
			lengths++;
	}
	opened = open(filename, O_WRONLY | O_APPEND);
	weight = write(opened, text_content, lengths);

	if (opened == -1 || weight == -1)
		return (-1);

	close(opened);
	return (1);
}
