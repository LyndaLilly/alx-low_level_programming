#include "main.h"
#include <stdio.h>
#include <stdlib.h>

char *file_content(char *context);
void finished_content(int file_directory);
/**
 * file_content - this is 1024 bytes for a buffer.
 * @context: the content of the file to creater.
 * Return: A file.
 */
char *file_content(char *context)
{
	char *buf;

	buf = malloc(sizeof(char) * 1024);

	if (buf == NULL)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", context);
		exit(99);
	}
	return (buf);
}

/**
 * finished_content - Closes file descriptors.
 * @file_directory: The file directory to be closed.
 */
void finished_content(int file_directory)
{
	int content;

	content = close(file_directory);

	if (content == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close %d\n", file_directory);
		exit(100);
	}
}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	int from, to, reads, writes;
	char *buf;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buf = file_content(argv[2]);
	from = open(argv[1], O_RDONLY);
	reads = read(from, buf, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (from == -1 || reads == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			free(buf);
			exit(98);
		}
		writes = write(to, buf, reads);

		if (to == -1 || writes == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			free(buf);
			exit(99);
		}
		reads = read(from, buf, 1024);
		to = open(argv[2], O_WRONLY | O_APPEND);
	} while (reads > 0);
	free(buf);
	finished_content(from);
	finished_content(to);
	return (0);
}
