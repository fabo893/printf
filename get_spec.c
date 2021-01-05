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
		{"d", sp_int},
		{"i", sp_int},
		{NULL, NULL}
	};
	int idx = 0;

	while (idx < 4)
	{
		if (*c == *sps[idx].op)
			return (sps[idx].f);
		idx++;
	}
	return (NULL);
}
