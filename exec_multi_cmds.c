#include "shell.h"

/**
 * exec_multi_cmds - Execute multiple commands separated by semicolons
 * @user_prompt: The user input string containing the commands
 * @sh_namee: program name
 * @cntt: cmonad count
 * Return: error code
 */
int exec_multi_cmds(char *user_prompt, char *sh_namee, int cntt)
{
	int num_of_cmds, num_of_words, i, ex_code;
	char **arr_of_cmds, **arr_of_wordss;

	arr_of_cmds = split_string(user_prompt, ";", &num_of_cmds);
	if (arr_of_cmds == NULL)
	{
		printf("Error splitting user input\n");
		return (errno);
	}

	for (i = 0; i < num_of_cmds; i++)
	{
		arr_of_wordss = split_string(arr_of_cmds[i], " \t\r\n", &num_of_words);
		if (arr_of_wordss == NULL)
		{
			perror("Error splitting command string\n");
			continue;
		}
		if (num_of_words == 0)
		{
			free_words(arr_of_cmds, num_of_cmds);
			free_words(arr_of_wordss, num_of_cmds);
			return (0);
		}
		if (my_strcmp(arr_of_wordss[0], "exit") == 0)
		{
			free_words(arr_of_cmds, num_of_cmds);
			handle_exit_with_status(arr_of_wordss, user_prompt,
			sh_namee, cntt, num_of_words);
		}
		ex_code = execute_by_forking(arr_of_wordss, user_prompt, sh_namee,
		cntt, num_of_words);
		free_words(arr_of_wordss, num_of_words);
	}

	free_words(arr_of_cmds, num_of_cmds);
	return (ex_code);
}
