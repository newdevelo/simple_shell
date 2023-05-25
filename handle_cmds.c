#include "shell.h"

/**
 * handle_various_cmds - handle env, setenv, unsetenv cmds
 * @arr_of_wordss: the cmds provided
 * @sh_namee: program name
 * @cntt: cmonad count
 * @nn: ------------------
 * @user_promptt: _______________
 * Return: 1 if one of the cmd is found or 0
*/

int handle_various_cmds(char **arr_of_wordss, char *user_promptt,
char *sh_namee, int cntt, int nn)
{
	char *cmd = arr_of_wordss[0];
	int cmd_was_handled = 0;
	(void)sh_namee, (void)cntt, (void)nn, (void)user_promptt;

	if (my_strcmp(cmd, "env") == 0)
	{
		handle_the_env();
		cmd_was_handled = 1;
	}
	else if (my_strcmp(cmd, "setenv") == 0)
	{
		if (arr_of_wordss[1] && arr_of_wordss[2])
			my_setenv(arr_of_wordss[1], arr_of_wordss[2], 1);
		else
			perror("Usage: setenv VARIABLE VALUE\nn");
		cmd_was_handled = 1;
	}
	else if (my_strcmp(cmd, "unsetenv") == 0)
	{
		if (arr_of_wordss[1])
			my_unsetenv(arr_of_wordss[1]);
		else
			perror("Usage: unsetenv VARIABLE\nn");
		cmd_was_handled = 1;
	}
	else if (my_strcmp(cmd, "cd") == 0)
	{
		my_cd(arr_of_wordss);
		cmd_was_handled = 1;
	}
	return (cmd_was_handled);
}
