#include "shell.h"

/**
 * my_memcpy - copies mem like c memcpy
 * @destinationn: the ...
 * @sourcee: the ...
 * @num_of_bytess: the ...
 * Return: void
*/
void *my_memcpy(void *destinationn, const void *sourcee,
size_t num_of_bytess)
{
	unsigned char *dest = destinationn;
	const unsigned char *src = sourcee;
	size_t idx;

	while (idx < num_of_bytess)
	{
		dest[idx] = src[idx];
		idx++;
	}
	return (destinationn);
}
