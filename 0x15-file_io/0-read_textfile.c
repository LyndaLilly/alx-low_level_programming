#include "main.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * read_textfile- Read text file print to STDOUT.
 * @filename: text file being read
 * @letters: is the number of letters it should read and print
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t total_read;
	ssize_t bytes_read;
	ssize_t total;

	total_read = open(filename, O_RDONLY);
	if (total_read == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	total = read(total_read, buffer, letters);
	bytes_read = write(STDOUT_FILENO, buffer, total);

	free(buffer);
	close(total_read);
	return (bytes_read);
}
