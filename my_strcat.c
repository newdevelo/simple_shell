#include "shell.h"

/**
 * my_strcat - Concatenates two strings
 * @destt: The destination string
 * @srcc: The source string
 * Return: A pointer to the destination string
 */
char *my_strcat(char *destt, const char *srcc)
{
	size_t dest_len = get_strlen(destt);

	my_strcpy(destt + dest_len, srcc);

	return (destt);
}

