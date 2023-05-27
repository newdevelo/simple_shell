#include "shell.h"

/**
 * file_exists - Checks if a file exists
 * @pathh: The pathh of the file to check
 * Return: 1 if the file exists, 0 otherwise
 */
int file_exists(const char *pathh)
{
	struct stat buffer;

	if (stat(pathh, &buffer) != 0)
		return (0);
	return (1);
}
