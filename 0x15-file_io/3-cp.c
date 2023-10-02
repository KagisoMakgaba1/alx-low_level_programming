#include "main.h"

/**
 * main - copies the content of a file to another file.
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, exit with error number, otherwise.
 */

int main(int argc, char *argv[])
{
	char *file_from, *file_to;
	char buffer[READ_BYTES];
	ssize_t r;
	int fd_read, fd_write, c = 0;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	file_from = argv[1];
	file_to = argv[2];
	fd_read = open(file_from, O_RDONLY);
	if (fd_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
	fd_write = open(file_to, O_CREAT | O_TRUNC | O_WRONLY, 00664);
	if (fd_write == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		exit(99);
	}

	while ((r = read(fd_read, buffer, READ_BYTES)))
		write(fd_write, buffer, r);
	if (close(fd_write))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_write);
		c = 1;
	}
	if (close(fd_read))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_read);
		c = 1;
	}
	if (c)
		exit(100);
	exit(EXIT_SUCCESS);
}
