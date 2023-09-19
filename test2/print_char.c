#include "main.h"
#include <stdarg.h>

/**
 * print_char - displays a character
 * @arguments: va_list arguments from _printf
 * Return: number of char printed
 */
int print_char(va_list arguments)
{
	int count;
	char get_char = va_arg(arguments, int);

	count = _putchar(get_char);
	return (count);
}
