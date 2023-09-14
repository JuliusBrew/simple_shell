#include "shell.h"

/**
 * interactive - returns true if shell in interactive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, else 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks if character is a delimiter
 * @c: the character to check
 * @del_str: the delimeter string
 * Return: 1 if true, 0 if false
 */

int is_delim(char c, char *del_str)
{
	while (*del_str)
		if (*del_str++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - checks for alphabetic character
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, else convert number
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int res = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			res *= 10;
			res += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -res;
	else
		output = res;

	return (output);
}
