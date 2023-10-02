#include "main.h"
#include <stdio.h>
/**
 * create_file - Creates a file.
 * @filename: is the name of the file to create and text_content is a NULL
 * @text_content: A pointer to a string to write to the file.
 * Return: 1 on success, -1 on failurE
 */
int create_file(const char *filename, char *text_content)
{
	int read_bytes, total_byted, length = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
	{
		for (length = 0; text_content[length];)
			length++;
	}
	read_bytes = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	total_byted = write(read_bytes, text_content, length);

	if (read_bytes == 1 || total_byted == -1)
		return (-1);

	close(read_bytes);
	return (1);
}
