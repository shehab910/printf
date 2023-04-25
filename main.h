#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
void handleNumber(int *count, va_list args, int base, int isSigned);
void handleString(int *count, va_list args);
void handleChar(int *count, va_list args);
void handlePercent(int *count);
void handleDefault(int *count, char c);
void handleHex(int *count, va_list args, int upper);
void handlePointer(int *count, va_list args);

#endif
