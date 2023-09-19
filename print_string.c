#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_string - a function to print out the characters
 * @arguments: variable value argument
 *
 * Return: numbers of printed characters || -1
 */
int print_string(va_list arguments)
{
	int count = 0;
	char *ptr = va_arg(arguments, char *);

	if (ptr == NULL)
	{
		ptr = "(null)";
	}
	while (*ptr)
	{
		count += _putchar(*ptr);
		ptr++;
	}

	return (count);
}
