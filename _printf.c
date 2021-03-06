#include "holberton.h"

/**
 * _printf - source code to the function of printf.
 * @format: Pointer to constant char (string).
 * Return: On success, the number of character printed.
 */
int _printf(const char *format, ...)
{
	va_list ls;
	int (*f)(va_list), idx, sum = 0;
	char prc = '%',  sp;

	if (format == NULL)
		return (-1);
	va_start(ls, format);
	for (idx = 0; format[idx] != '\0'; idx++)
	{
		if (format[idx] == '%')
		{
			if (format[idx + 1] == '\0')
				return (-1);
			else if (format[idx + 1] == '%')
			{
				write(1, &prc, 1);
				sum += 1;
				idx++;
			}
			else
			{
				sp = format[idx + 1];
				f = get_spec(&sp);
				if (f == NULL)
					sum += write(1, &prc, 1);
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
			sum += 1;
		}
	}
	va_end(ls);
	return (sum);
}
