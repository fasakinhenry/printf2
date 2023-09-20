#include "main.h"

/**
 * get_width - wih to be printed
 * @format: string to print
 * @i: bunch of arguments to be printed
 * @list: args variadic
 *
 * Return: width.
 */

int get_width(const char *format, int *i, va_list list)
{
	int widthh = 0;
	int current_i;

	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			widthh *= 10;
			widthh += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			widthh = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_i - 1;

	return (widthh);
}
