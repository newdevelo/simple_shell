#include "shell.h"

/**
 * get_strlen - get string length
 * @strr: the string
 * Return: length
*/

size_t get_strlen(const char *strr)
{
	size_t ans = 0;

	while (*strr != '\0')
	{
		ans++;
		strr++;
	}
	return (ans);
}
