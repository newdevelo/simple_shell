#include "shell.h"

/**
 * handle_exit_with_status - Handles exit built-in command.
 * @arr_of_wordss: commands
 * @user_promptt: user input.
 * @sh_namee: program name
 * @cntrr: conter of commands
 * @nn: number of commands
 * Return: void.
 */
void handle_exit_with_status(char **arr_of_wordss, char *user_promptt,
char *sh_namee, int cntrr, int nn)
{
	int ex_stat, i = 0;

	if (arr_of_wordss[1] == NULL)
	{
		free(user_promptt);
		free_words(arr_of_wordss, nn);
		exit(EXIT_SUCCESS);
	}

	while (arr_of_wordss[1][i])
	{
		if (my_isdig(arr_of_wordss[1][i++]) == 0)
		{
			ex_err(arr_of_wordss, cntrr, sh_namee);
			break;
		}
		else
		{
			ex_stat = my_atoi(arr_of_wordss[1]);
			free(user_promptt);
			free_words(arr_of_wordss, nn);
			exit(ex_stat);
		}
	}

}
