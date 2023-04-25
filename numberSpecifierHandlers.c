#include <stdio.h>
#include "main.h"

/**
 * print_number - converts an integer to a string and prints it
 * @n: integer to be converted
 * @count: pointer to the count of characters printed
 * @base: base to convert integer to
 * @isSigned: 1 if integer is signed, 0 if unsigned
 * @isUpper: 1 if hex letters should be uppercase, 0 if lowercase
 */
void print_number(int n, int *count, int base, int isSigned, int isUpper)
{
	unsigned int num = n, digit;

	if (isSigned && n < 0)
	{
		_putchar('-');
		(*count)++;
		num = -num;
	}
	if (num / base)
		print_number(num / base, count, base, isSigned, isUpper);
	digit = num % base;
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
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 * @base: base to convert integer to
 * @isSigned: 1 if integer is signed, 0 if unsigned
 */
void handleNumber(int *count, va_list args, int base, int isSigned)
{
	int j;

	j = va_arg(args, int);
	print_number(j, count, base, isSigned, 0);
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
