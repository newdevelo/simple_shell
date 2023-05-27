#include "shell.h"

/**
 * env_vars - Gets the value of an environment variable.
 * @env_namee: The name of the environment variable.
 * @env_pointerr: Pointer to the environment variables array.
 *
 * Return: The value of the environment variable.
 */
char *env_vars(const char *env_namee, char **env_pointerr)
{
	char **the_env;

	for (the_env = env_pointerr; *the_env != NULL; the_env++)
	{
		if (strncmp(env_namee, *the_env, get_strlen(env_namee)) == 0
				&& (*the_env)[get_strlen(env_namee)] == '=')
		{
			return (*the_env + get_strlen(env_namee) + 1);
		}
	}
	return (NULL);
}

/**
 * isError - Prints an error message.
 * @msg: The error message to print.
 */
void isError(const char *msg)
{
	printf("cd: %s\n", msg);
}

/**
 * get_dir - Gets the directoryy to change to.
 * @initial_pathh: The initial path passed to cd.
 *
 * Return: The directoryy to change to.
 */
char *get_dir(const char *initial_pathh)
{
	if (initial_pathh == NULL)
		return (env_vars("HOME", environ));
	else if (my_strcmp(initial_pathh, "-") == 0)
		return (env_vars("the_old_pwd", environ));
	else
		return ((char *)initial_pathh);
}

/**
 * handle_cwd - Gets the current working directoryy.
 *
 * Return: The current working directoryy.
 */
char *handle_cwd()
{
	char *the_cwd;

	the_cwd = getcwd(NULL, 0);
	if (the_cwd == NULL)
		perror("cd");
	return (the_cwd);
}

/**
 * switch_current_directory - Changes the current working directoryy.
 * @directoryy: The directoryy to change to.
 */
void switch_current_directory(const char *directoryy)
{
	if (chdir(directoryy) < 0)
		perror("cd");
}

