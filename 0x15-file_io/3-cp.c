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
	int file_from = open(argv[1], O_RDONLY);
	int file_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	ssize_t n;
	char buffer[BUFF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		exit(99);
	}
	while ((n = read(file_from, buffer, BUFF_SIZE)) > 0)
	{
		if (write(file_to, buffer, n) != n)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			exit(99);
		}
	}
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if ((close(file_from) == -1) || (close(file_to) == -1))
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n",
				(close(file_from) == -1) ? file_from : file_to);
		exit(100);
	}
	exit(EXIT_SUCCESS);
}
