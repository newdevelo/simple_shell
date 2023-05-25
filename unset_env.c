#include "shell.h"

/**
 * my_unsetenv - Unset an environment variable.
 * @env_namee: The name of the env var to unset.
 * Return: 0 on success, or -1.
 */
int my_unsetenv(const char *env_namee)
{
	int final_result;

	if (!env_namee || env_namee[0] == '\0')
	{
		perror("unsetenv: invalid env name\n");
		return (-1);
	}

	final_result = unsetenv(env_namee);

	if (final_result < 0)
		perror("unsetenv: failed to unset env\n");

	return (final_result);
}
