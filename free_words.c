#include "shell.h"

/**
 * free_words - Frees a list of wordss.
 * @wordss: Pointer to an array of strings.
 * @num_of_wordss: Number of wordss in the array.
 * This function frees each individual string in the array using the
 * free() function and finally frees the array itself using free().
 */
void free_words(char **wordss, int num_of_wordss)
{
	int i;

	if (wordss == NULL)
		return;
	for (i = 0; i < num_of_wordss; i++)
	{
		if (wordss[i] != NULL)
		{
			free(wordss[i]);
			wordss[i] = NULL;
		}
	}
	free(wordss);
}
