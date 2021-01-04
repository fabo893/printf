#include "holberton.h"

/**
 * _printf - source code to the function of printf.
 * @format: Pointer to constant char (string).
 * Return: On success, the number of character printed.
 */
int _printf(const char *format, ...)
{
	va_list ls;
	int idx;
	int (*f)(va_list);
	char prc = '%';
	char sp;
	int sum = 0;

	if (format == NULL)
		return (-1);

	va_start(ls, format);

	if (format == NULL)
		return (-1);

	for (idx = 0; format[idx] != '\0'; idx++)
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '%')
			{
				write(1, &prc, 1);
				idx++;
			}
			else
			{
				sp = format[idx + 1];
				f = get_spec(&sp);
				if (f == NULL)
				{
					write(1, &prc, 1);
				}
				else
				{
					sum += f(ls);
					idx++;
				}
			}
		}
		else
		{
			write(1, &format[idx], 1);
		}
	}
	va_end(ls);

	if (sum > 0)
		idx = (idx - 2) + sum;

	return (idx);
}
