#include "shell.h"

/**
 * my_atoi - implementation of built in atoi
 * @stringg: the stringg
 * Return: integer
*/

int my_atoi(const char *stringg)
{
	int ans = 0, sign_val = 1;

	while (*stringg == ' ' || *stringg == '\t' || *stringg == '\n')
		stringg++;

	if (*stringg == '-')
	{
		sign_val = -1;
		stringg++;
	}
	else if (*stringg == '+')
		stringg++;

	while (*stringg >= '0' && *stringg <= '9')
	{
		ans = ans * 10 + (*stringg - '0');
		stringg++;
	}

	return (sign_val * ans);
}
