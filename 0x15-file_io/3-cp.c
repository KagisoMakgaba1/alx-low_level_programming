#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#define BUFFER_SIZE 1024

/**
 * print_error - print file close error
 * @file_des: file descriptor
 * Return: nothing
 */

void *print_error(int file_des)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", file_des);
	exit(100);
}

/**
 * main - copy content of one file into another
 * @argc: argument count
 * @argv: argument vector
 * Return: EXIT_SUCCESS on success, otherwise exit with error number
 */

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	int fd_from, fd_to, k;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(argv[1], O_RDONLY);
	if (argv[1] == NULL || fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close(fd_from);
		exit(99);
	}
	while ((k = read(fd_from, buffer, 1024)) > 0)
	{
		if (k != write(fd_to, buffer, k))
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
			close(fd_from);
			close(fd_to);
			exit(99);
		}}
	if (k < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98); }
	if (close(fd_from) < 0)
		print_error(fd_from);
	if (close(fd_to) < 0)
		print_error(fd_to);
return (0);
}
