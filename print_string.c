#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_string - a function to print out the characters
 * @args: variable value argument
 * @printed_chars: pointer to the formart specifier
 *
 * Return: numbers of printed characters || -1
 */
void print_string(va_list arguments, int *printed_chars)
{
	char *str = va_arg(arguments, char *);

	if (str != NULL)
	{
		int len = str_len(str);

		write(1, str, len);
		(*printed_chars) += len;
	}
	else
	{
		write(1, "(null)", 6);
		(*printed_chars) += 6;
	}
}
