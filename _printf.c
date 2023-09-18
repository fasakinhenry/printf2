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

checkForm *get_format_handlers()
{
	static checkForm formatchk[] = {
		{'c', print_char},
		{'s', print_string},
	};
	return (formatchk);
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
	
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				handle_percent(&charlength);
			}
			else
			{
				checkForm *formatchk = get_format_handlers();

				for (i = 0; i < 2; i++)
				{
					if (*format == formatchk[i].opt)
					{
						formatchk[i].opt_func(arguments, &charlength);
					}
				}
			}
		}
		else
		{
			_putchar(*format);
			charlength++;
		}
		format++;
	}
	va_end(arguments);
	return (charlength);
}
