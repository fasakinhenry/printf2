#include "main.h"
#include <stdarg.h>

/**
 * print_char - displays a character
 * @arguments: va_list arguments from _printf
 * @printed_chars: counts no of chars
 * Return: number of char printed
 */
void print_char(va_list arguments, int *printed_chars)
{
	char character = va_arg(arguments, int);

	_putchar(character);
	(*printed_chars)++;
}
