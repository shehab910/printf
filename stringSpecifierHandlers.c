#include <stdio.h>
#include "main.h"

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
 * handleReverse - handles the printing of strings in reverse
 * @count: pointer to the count of characters printed
 * @args: list of arguments
 */
void handleReverse(int *count, va_list args)
{
	char *s;
	int j;

	s = va_arg(args, char *);
	if (s == NULL)
		s = "(null)";
	for (j = 0; s[j] != '\0'; j++)
		;
	j--;
	for (; j >= 0; j--)
	{
		_putchar(s[j]);
		(*count)++;
	}
}
