#include "shell.h"

/**
 * my_strcmp - Compares two strings.
 * @firstt: The firstt string
 * @secondd: The secondd string
 * Return: An integer;
 */
int my_strcmp(const char *firstt, const char *secondd)
{
	while (*firstt == *secondd && *firstt != '\0')
	{
		firstt++;
		secondd++;
	}

	return ((int)(*firstt) - (int)(*secondd));
}
