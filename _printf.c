#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * handleCases - handles the cases for the format specifier
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 * @fChar: format character
 */
void handleCases(int *count, va_list args, const char fChar)
{
	switch (fChar)
	{
	case 'c':
		handleChar(count, args);
		break;
	case 's':
		handleString(count, args);
		break;
	case '%':
		handlePercent(count);
		break;
	case 'd':
	case 'i':
		handleNumber(count, args, 10, 1);
		break;
	case 'u':
		handleNumber(count, args, 10, 0);
		break;
	case 'b':
		handleNumber(count, args, 2, 0);
		break;
	case 'o':
		handleNumber(count, args, 8, 0);
		break;
	case 'x':
		handleHex(count, args, 0);
		break;
	case 'X':
		handleHex(count, args, 1);
		break;
	case 'p':
		handlePointer(count, args);
		break;
	case 'r':
		handleReverse(count, args);
		break;
	default:
		handleDefault(count, fChar);
		break;
	}
}

/**
 * _printf -  produces output according to a format.
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * You need to handle the following conversion specifiers:
 * c, s, %, d, i, u, o, x, X
 * You don’t have to handle:
 * reproduction of the buffer handling of the C
 * library printf function
 * the flag characters
 * field width
 * precision
 * the length modifiers
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			handleCases(&count, args, format[i]);
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
