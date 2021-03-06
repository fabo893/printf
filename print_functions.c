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
 * Return: On success, the length of the string.
 */
int sp_str(va_list ls)
{
	char *str = va_arg(ls, int);
	char *non = "(null)";
	int idx = 0;

	if (str == NULL)
	{
		while (non[idx] != '\0')
		{
			write(1, &non[idx], 1);
			idx++;
		}
	}
	else
	{
		while (str[idx] != '\0')
		{
			write(1, &str[idx], 1);
			idx++;
		}
	}

	return (idx);
}


/**
 * sp_int - function to print a integer.
 * @ls: list of arguments for get integer.
 * Return: On success, 1.
 */
int sp_int(va_list ls)
{
	long int x = va_arg(ls, int), i = 0, a, idx;
	char minus = '-';
	int *array;

	if (x == 0)
	{
		_putchar(x + '0');
		i = 1;
	}
	else
	{
		if (x < 0)
		{
			_putchar(minus);
			x = (x * -1);
			i += 1;
		}

		array = malloc(sizeof(int) * 20);
		if (array == NULL)
			return (0);

		idx = 0;
		while (x != 0)
		{
			a = x % 10;
			array[idx] = a;
			x = x / 10;
			idx++;
		}
		i += idx;

		idx--;
		while (idx > -1)
		{
			_putchar(array[idx] + '0');
			idx--;
		}
		free(array);
	}
	return (i);
}
