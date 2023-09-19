#include "main.h"
#include <unistd.h>


/**
 * str_len - to get the length of a string
 * @s: string
 * Return: returns the length
 */

int str_len(const char *s)
{
	int len = 0;

	while (*s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}
/**
 * handle_percent - print a percent sign
 * @printed_chars: no of chars
 */
void handle_percent(int *printed_chars)
{
	_putchar('%');
	(*printed_chars)++;
}
/**
 * selector - picks function to be run
 * @str: format
 * Return: 0
 */
int (*selector(char str))(va_list arg)
{
	if (str == 'c')
	{
		return (&print_char);
	}
	else if (str == 'd')
	{
		return (&print_decimal);
	}
	else if (str == 's')
	{
		return (&print_string);
	}
	return (0);
}

/**
 * _printf - printf function
 * @format: format specified
 * Return: formatted output
 */

int _printf(const char *format, ...)
{
	int charlength = 0;
	int i;
	va_list arguments;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				handle_percent(&charlength);
			} else
			{
				if (format[i] == 'c' || format[i] == 'd' || format[i] == 's')
				{
					charlength += selector(format[i])(arguments);
				}
			}
		}
		else
		{
			_putchar(format[i]);
			charlength++;
		}
	}
	va_end(arguments);
	return (charlength);
}
