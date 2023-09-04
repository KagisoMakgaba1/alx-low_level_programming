#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: is a NULL terminated string to write
 * to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t w = 0;
	ssize_t j = 0;

	if (filename == NULL)
		return (-1);

	for (j = 0; text_content && text_content[j]; j++)
		;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR | S_IWUSR);

	if (fd == -1)
		return (-1);

	if (j)
		w = write(fd, text_content, j);
	close(fd);

	if (w == -1)
		return (-1);

	return (1);
}
