#include "shell.h"

/**
 * split_string - splits a string into an array of words
 * @strr: the strr to be splited
 * @str_separatorr: the delimeter
 * @num_of_wordss: number of words in the strr
 * Return: the array of string or NULL
*/

char **split_string(char *strr, const char *str_separatorr, int *num_of_wordss)
{
	char *str_copy = NULL, *word = NULL, **arr_of_wordss;
	int i;

	str_copy = malloc(sizeof(char) * get_strlen(strr) + 1);
	if (str_copy == NULL)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	my_strcpy(str_copy, strr);

	*num_of_wordss = 0;
	word = strtok(strr, str_separatorr);
	while (word != NULL)
	{
		(*num_of_wordss)++;
		word = strtok(NULL, str_separatorr);
	}
	arr_of_wordss = malloc(sizeof(char *) * (*num_of_wordss + 1));
	if (arr_of_wordss == NULL)
	{
		perror("Allocation Failed !");
		return (NULL);
	}
	word = strtok(str_copy, str_separatorr);
	for (i = 0; word != NULL; i++)
	{
		arr_of_wordss[i] = malloc(sizeof(char) * get_strlen(word) + 1);
		if (arr_of_wordss[i] == NULL)
		{
			perror("Allocation Failed !");
			return (NULL);
		}
		my_strcpy(arr_of_wordss[i], word);
		word = strtok(NULL, str_separatorr);
	}

	arr_of_wordss[i] = NULL;
	free(str_copy);
	return (arr_of_wordss);
}
