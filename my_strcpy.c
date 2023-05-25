#include "shell.h"

/**
 * my_strcpy - copies a srcc to destt
 * @destt: destt str
 * @srcc: the string
 * Return: the copied string
*/

char *my_strcpy(char *destt, const char *srcc)
{
	char *p = destt;

	while (*srcc != '\0')
	{
		*p++ = *srcc++;
	}
	*p = '\0';
	return (destt);
}
