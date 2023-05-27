#include "shell.h"

/**
 * my_strdup - Duplicates a string
 * @ss: The string
 * Return: new string pointer or NULL
 */
char *my_strdup(const char *ss)
{
	size_t len = get_strlen(ss), i;
	char *dup = malloc(len + 1);

	if (dup)
	{
		for (i = 0; i < len; i++)
			dup[i] = ss[i];
		dup[len] = '\0';
	}

	return (dup);
}
