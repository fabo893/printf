#include "holberton.h"

/**
 * *get_spec - Check the specifier for get the function.
 * @c: Pointer to char of the specifier.
 * Return: On success, pointer of the function.
 */
int (*get_spec(char *c))(va_list)
{
	spec_t sps[] = {
		{"c", sp_chr},
		{"s", sp_str},
		{NULL, NULL}
	};
	int idx = 0;

	while (idx < 2)
	{
		if (*c == *sps[idx].op)
			return (sps[idx].f);
		idx++;
	}
	return (NULL);
}
