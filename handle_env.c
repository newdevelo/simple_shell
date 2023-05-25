#include "shell.h"

/**
 * handle_the_env - Prints the env variables.
 * Return: void
 */

void handle_the_env(void)
{
	char **env_pointerr = environ;

	while (*env_pointerr)
	{
		printf("%s\n", *env_pointerr);
		env_pointerr++;
	}
}
