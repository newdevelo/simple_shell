#include "shell.h"

/**
 * read_from_input  - reads input
 * @char_to_readd: the chars
 * Return: 1 if read else 0
*/

int read_from_input(char *char_to_readd)
{
	ssize_t start = read(STDIN_FILENO, char_to_readd, 1);

	if (start == -1)
		return (0);
	if (start == 0)
	{
		if (char_to_readd != NULL)
			char_to_readd[0] = '\0';
		return (0);
	}
	return (1);
}

/**
 * my_realloc  - same as C realloc
 * @old_ptrr: the old one
 * @sizee: curr sizee
 * Return: void
*/

void *my_realloc(void *old_ptrr, size_t sizee)
{
	void *new_ptr;

	if (sizee == 0)
	{
		free(old_ptrr);
		return (NULL);
	}

	new_ptr = malloc(sizee);
	if (new_ptr == NULL)
	return (NULL);

	if (old_ptrr != NULL)
	{
		my_memcpy(new_ptr, old_ptrr, sizee);
		free(old_ptrr);
	}

	return (new_ptr);
}

/**
 * update_buff  - updates the storage buffer
 * @buff_ptr: pointer
 * @buff_size: the sizee of buff
 * @buffer: storage
 * @idx: current position of buffer
 * Return: void
*/
void update_buff(char **buff_ptr, size_t *buff_size, char *buffer, size_t idx)
{
	if (*buff_ptr == NULL || *buff_size < idx)
	{
		*buff_size = (idx > STORAGE_SIZE) ? idx : STORAGE_SIZE;
		*buff_ptr = buffer;
	}
	else
	{
		my_strcpy(*buff_ptr, buffer);
		free(buffer);
	}
}

