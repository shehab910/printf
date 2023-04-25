#include "main.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * print_char - print a single to standard output
 *
 * @args: variable argument list
 *
 * Return: the number of characters written
 * 
 */
int print_char(va_list args)
{
	char c = va_args(args, int);

	return (write(1, &c 1));
}
