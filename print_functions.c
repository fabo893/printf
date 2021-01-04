#include "holberton.h"

/**
 * sp_chr - function to print one char.
 * @ls: list of arguments for get the char.
 * Return: On success, 1.
 */
int sp_chr(va_list ls)
{
	char x = va_arg(ls, int);

	return (write(1, &x, 1));
}


/**
 * sp_str - function to print a string.
 * @ls: list of arguments for get the string.
 * Return: On success, 1.
 */
int sp_str(va_list ls)
{
	char *str = va_arg(ls, int);
	int idx = 0;

	while (str[idx] != '\0')
	{
		write(1, &str[idx], 1);
		idx++;
	}

	return (1);
}
