#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>


/**
 * struct specs - struct for specifiers and functions.
 * @op: Pointer to char of the specifiers.
 * @f: Pointer to function.
 */
typedef struct specs
{
	char *op;
	int (*f)(va_list);
} spec_t;

/* PRINTF */
int _printf(const char *format, ...);

/* CHECK SPECIFIERS */
int (*get_spec(char *c))(va_list);

/* PRINT FUNCTIONS */
int sp_chr(va_list ls);
int sp_str(va_list ls);
int sp_dig(va_list ls);
int sp_int(va_list ls);

#endif /* HOLBERTON_H */
