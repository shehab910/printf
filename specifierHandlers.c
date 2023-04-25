#include <stdio.h>
#include "main.h"

/**
 * print_number - converts an integer to a string and prints it
 * @n: integer to be converted
 * @count: pointer to the count of characters printed
 */
void print_number(int n, int *count, int base, int isSigned, int isUpper)
{
	unsigned int num = n;

	if (isSigned && n < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}
	if (num / base)
		print_number(num / base, count, base, isSigned, isUpper);
	unsigned int digit = num % base;
	if (digit < 10)
		_putchar(digit + '0');
	else
	{
		if (isUpper)
			_putchar(digit - 10 + 'A');
		else
			_putchar(digit - 10 + 'a');
	}
	(*count)++;
}

/**
 * handleNumber - handles the printing of numbers
 * @j: integer to be printed
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 */
void handleNumber(int *count, va_list args, int base, int isSigned)
{
	int j;

	j = va_arg(args, int);
	print_number(j, count, base, isSigned, 0);
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

/**
 * handleDefault - handles the default case
 * @count: pointer to the count of characters printed
 * @c: character to be printed
 *
 */
void handleDefault(int *count, char c)
{
	_putchar('%');
	_putchar(c);
	(*count) += 2;
}

/**
 * handleHex - handles the printing of hexadecimal numbers
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 * @upper: flag to determine if hex should be uppercase
 */
void handleHex(int *count, va_list args, int upper)
{
	int j;
	unsigned int num;

	j = va_arg(args, int);
	num = j;
	print_number(num, count, 16, 0, upper);
}