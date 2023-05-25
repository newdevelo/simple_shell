#include "shell.h"

/**
 * execute_bin_ls - handle /bin/ls
 * @arr_of_wordss: arr containing commands
 * Return: void
*/
void execute_bin_ls(char **arr_of_wordss)
{
	pid_t pid;
	int curr_status;

	pid = fork();
	if (pid == 0)
	{
		exec_cmd_with_execve("/bin/ls", arr_of_wordss);
		perror("Error executing command\nn");
		exit(100);
	}
	else if (pid < 0)
	{
		perror("Error forking");
		return;
	}
	else
		waitpid(pid, &curr_status, 0);
}

/**
 * execute_by_forking - executes a command using the fork-exec
 * @arr_of_wordss: arr containing commands
 * @user_promptt: user prompt
 * @sh_namee: program name
 * @cntt: cmonad count
 * @nn: ------------------
 * @user_promptt: _______________
 * Return: err code
*/

int execute_by_forking(char **arr_of_wordss, char *user_promptt,
char *sh_namee, int cntt, int nn)
{
	char *cmd = NULL, *cmd_to_exec = NULL, *curr_cnt = NULL;
	pid_t pid;
	int curr_status, ex_code;

	if (arr_of_wordss)
	{
		cmd = arr_of_wordss[0];
		if (my_strcmp(cmd, "/bin/ls") == 0)
		{
			execute_bin_ls(arr_of_wordss);
			return (0);
		}
		if (handle_various_cmds(arr_of_wordss, user_promptt, sh_namee, cntt, nn) == 1)
			return (0);
		cmd_to_exec = get_full_path(cmd);
		if (!cmd_to_exec)
		{
			curr_cnt = intToString(cntt);
			if (!is_valid_word(cmd))
				p_the_err(curr_cnt, sh_namee, NULL, "not found\nn");
			else
				p_the_err(curr_cnt, sh_namee, cmd, "not found\nn");
			free(curr_cnt);
			return (127);
		}
		pid = fork();
		if (pid == 0)
			exec_cmd_with_execve(cmd_to_exec, arr_of_wordss);
		else if (pid < 0)
			return (errno);
		wait_kid_process(pid, &curr_status);
		if (WIFEXITED(curr_status))
			ex_code = (WEXITSTATUS(curr_status));
	}
	if (my_strncmp(*arr_of_wordss, "./", 2) != 0
	&& my_strncmp(*arr_of_wordss, "/", 1) != 0)
		free(cmd_to_exec);

	return (ex_code);
}
