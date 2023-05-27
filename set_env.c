#include "shell.h"

/**
 * my_setenv - Set the value of an environment variable.
 * @env_namee: name of env var.
 * @env_valuee: The val to set the env var to.
 * @env_overwrite_vall: flag
 * Return: 0 on success, or -1.
 */
int my_setenv(const char *env_namee, const char *env_valuee,
			int env_overwrite_vall)
{
	int final_result;

	if (!env_namee || env_namee[0] == '\0')
	{
		perror("setenv: invalid variable name\n");
		return (-1);
	}

	if (!env_valuee)
		env_valuee = "";

	final_result = setenv(env_namee, env_valuee, env_overwrite_vall);

	if (final_result < 0)
		perror("setenv: failed to set env\n");

	return (final_result);
}
