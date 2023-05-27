#include "shell.h"

/**
 * get_dir_path - Concatenates a directory pathh and a command name
 * @pathh: The directory pathh
 * @cmdd: The command name
 *
 * Return: new string with the concatenated pathh and command name
 */
char *get_dir_path(const char *pathh, const char *cmdd)
{
	char *dir_path = malloc(get_strlen(pathh) + get_strlen(cmdd) + 2);

	if (!dir_path)
		return (NULL);

	my_strcpy(dir_path, pathh);
	my_strcat(dir_path, "/");
	my_strcat(dir_path, cmdd);

	return (dir_path);
}
