#include "main.h"

/**
 * append_text_to_file - appends text at the end of a file.
 * @filename: name of file to append to
 * @text_content: the NULL terminated string to add at the end of the file
 *
 * Return: 1 on success and -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fd, s;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_APPEND | O_WRONLY);
	if (fd == -1)
		return (-1);

	for (s = 0; text_content && text_content[s]; s++)
		;

	if (write(fd, text_content, s) != s)
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (1);
}
