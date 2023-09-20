#include "main.h"

/**
 * handles_printing - gives output arg according to type
 *
 * @fmt: string to print the arguments
 * @list: List of args to be printed
 * @ind: idk
 * @buffer: arr that holds print
 * @flags: gets all flags
 * @width: gets the width
 * @precision: get prscn
 * @size: Size
 *
 * Return: 1 / 2;
 */

int handles_printing(const char *fmt, int *ind, va_list list, char buffer[],
int flags, int width, int precision, int size)
{
	int unknow_len = 0;
	int i;
	int printed_chars = -1;

	fmt_t fmt_types[] = {
		{'c', output_char}, {'s', output_string}, {'%', output_percent},
		{'i', output_int}, {'d', output_int}, {'b', output_binary},
		{'u', output_unsigned}, {'o', output_octal}, {'x',
								   output_hexadecimal},
		{'X', output_hexa_upper}, {'p', output_pointer}, {'S',
								       output_non_printable},
		{'r', output_reverse}, {'R', output_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width,
						precision, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
