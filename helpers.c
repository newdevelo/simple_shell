#include "shell.h"

/**
 * intToString - int to a str
 * @numm: integg
 * Return: str
 */
char *intToString(int numm)
{
	int negative_num = 0, digCntr = 0, tmp, i = 0, j = 0;
	char *str;

	if (numm < 0)
	{
		negative_num = 1;
		numm *= -1;
		digCntr++;
	}
	tmp = numm;
	while (tmp > 0)
	{
		digCntr++;
		tmp /= 10;
	}
	str = (char *) malloc(sizeof(char) * (digCntr + 1));
	do {
		str[i++] = (numm % 10) + '0';
		numm /= 10;
	} while (numm);

	if (negative_num)
	{
		str[i++] = '-';
	}

	j = i - 1;
	i = 0;
	while (i < j)
	{
		char tmp = str[i];

		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}

	str[digCntr] = '\0';
	return (str);
}

/**
 * my_isdig- is digit
 * @c: integg
 * Return: bool
 */
int my_isdig(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
