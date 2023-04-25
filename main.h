#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void handleNumber(int j, int *count, va_list args);
void handleString(int *count, va_list args);
void handleChar(int *count, va_list args);
void handlePercent(int *count);

#endif
