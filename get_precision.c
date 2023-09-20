#include "main.h"

/**
 * get_prcn - get precision to print
 * @format: string parsed as argument
 * @i: comprises ofarguments that should be printed
 * @list: bunch of args
 *
 * Return: returns the precision
 */

int get_prcn(const char *format, int *i, va_list list)
{
	int current_i = *i + 1;
	int prcn = -1;

	if (format[current_i] != '.')
		return (prcn);
	prcn = 0;

	for (current_i += 1; format[current_i] != '\0'; current_i++)
	{
		if (is_digit(format[current_i]))
		{
			prcn *= 10;
			prcn += format[current_i] - '0';
		}
		else if (format[current_i] == '*')
		{
			current_i++;
			prcn = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = current_i - 1;

	return (prcn);
}
