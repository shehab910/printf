#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf -  produces output according to a format.
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * You need to handle the following conversion specifiers:
 * c,s, %
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
	char *s;

	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				j = va_arg(args, int);
				_putchar(j);
				count++;
				break;
			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				for (j = 0; s[j] != '\0'; j++)
				{
					_putchar(s[j]);
					count++;
				}
				break;
			case '%':
				_putchar('%');
				count++;
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
