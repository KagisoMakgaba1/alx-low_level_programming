#include "main.h"
#include <fcntl.h>
#include <unistd.h>

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: a NULL terminated string to write to the file
 *
 * Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	size_t n = 0;
	ssize_t p = 0;
	int fd;

	if (filename == NULL)
		return (-1);

	for (n = 0; text_content && text_content[n]; n++)
		;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY | S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (n)
		p = write(fd, text_content, n);
	close(fd);

	if (p == -1)
		return (-1);
	return (1);
}
