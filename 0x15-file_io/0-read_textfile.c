#include "main.h"
#include <stdlib.h>

/**
 * read_textfile -  reads a text file and prints it to
 * the POSIX standard output.
 * @filename: the text file that is read
 * @letters: the number of letters it should read and print
 *
 * Return: number of letters it could read and print,
 * 0 if filename is NULL
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	ssize_t r;
	ssize_t w;
	int fd;

	fd = open(filename, O_RDONLY);

	if (fd == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	r = read(fd, buffer, letters);
	w = write(STDOUT_FILENO, buffer, r);

	free(buffer);
	close(fd);
	return (w);
}
