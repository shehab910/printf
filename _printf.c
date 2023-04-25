#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf -  produces output according to a format.
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * You need to handle the following conversion specifiers:
 * c, s, %, d, i
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
	int i = 0, j = 0, count = 0;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
			case 'c':
				handleChar(&count, args);
				break;
			case 's':
				handleString(&count, args);
				break;
			case '%':
				handlePercent(&count);
				break;
			case 'd':
			case 'i':
				handleNumber(j, &count, args);
				break;
			default:
				_putchar('%');
				_putchar(format[i]);
				count += 2;
				break;
			}
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
