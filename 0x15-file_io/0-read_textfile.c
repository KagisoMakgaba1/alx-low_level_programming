#include "main.h"

/**
 * read_textfile - read a text file and print to STDOUT
 * @filename: path of filename to read
 * @letters: number of letters to read and write
 *
 * Return: the actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	char *buffer;
	int fd;
	ssize_t n, w;

	if (filename == NULL)
		return (0);

	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buffer);
		return (0);
	}

	n = read(fd, buffer, letters);
	if (n == -1)
	{
		free(buffer);
		close(fd);
		return (0);
	}
	close(fd);

	w = write(STDOUT_FILENO, buffer, n);
	if (w == -1)
	{
		free(buffer);
		return (0);
	}
	if (w != n)
		return (0);
	return (n);
}
