#include "shell.h"


/**
 * p_the_err - errrorrorrooror
 * @sh_namee: naaaaaaame
 * @cmd: cmmmmmmd
 * @msgg: mssssg
 * @cntt: cmonad count
 * Return: void
*/
void p_the_err(char *cntt, char *sh_namee, char *cmd, char *msgg)
{
	write(STDERR_FILENO, sh_namee, get_strlen(sh_namee));
	if (cmd != NULL)
	{
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cntt, get_strlen(cntt));
		write(STDERR_FILENO, ": ", 2);
		write(STDERR_FILENO, cmd, get_strlen(cmd));
	}
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, msgg, get_strlen(msgg));
}

/**
 * ex_err- errrorrorrooror
 * @sh_namee: naaaaaame
 * @arr_of_words: akfjalal
 * @cntr: cmonad count
 * Return: void
*/
void ex_err(char **arr_of_words, int cntr, char *sh_namee)
{
	char *err_code = intToString(cntr);

	write(STDOUT_FILENO, sh_namee, get_strlen(sh_namee));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, err_code, get_strlen(err_code));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, arr_of_words[0], get_strlen(arr_of_words[0]));
	write(STDOUT_FILENO, ": Illegal number: ", 19);
	write(STDOUT_FILENO, arr_of_words[1], get_strlen(arr_of_words[1]));
	write(STDOUT_FILENO, "\n", 2);
	free(err_code);
}
