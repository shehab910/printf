#include <stdio.h>
#include "main.h"

/**
 * print_number - converts an integer to a string and prints it
 * @n: integer to be converted
 * @count: pointer to the count of characters printed
 */
void print_number(int n, int *count)
{
	unsigned int num = n;

	if (n < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}
	if (num / 10)
		print_number(num / 10, count);

	_putchar((num % 10) + '0');
	(*count)++;
}

/**
 * handleNumber - handles the printing of numbers
 * @j: integer to be printed
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 */
void handleNumber(int j, int *count, va_list args)
{
	j = va_arg(args, int);
	print_number(j, count);
}

/**
 * handleString - handles the printing of strings
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 */
void handleString(int *count, va_list args)
{
	char *s;
	int j;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (j = 0; s[j] != '\0'; j++)
	{
		_putchar(s[j]);
		(*count)++;
	}
}

/**
 * handleChar - handles the printing of characters
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 */
void handleChar(int *count, va_list args)
{
	int j;

	j = va_arg(args, int);
	_putchar(j);
	(*count)++;
}

/**
 * handlePercent - handles the printing of percent signs
 * @count: pointer to the count of characters printed
 */
void handlePercent(int *count)
{
	_putchar('%');
	(*count)++;
}
