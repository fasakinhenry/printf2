#include "main.h"

/**
 * output_unsigned - Prints an unsigned num immediately
 * @types: List a of arguments
 * @buffer: Buffer arr that handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size ,,,
 * Return: No of chars printdd
 */

int output_unsigned(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * output_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer arr to handle print
 * @flags: gets active flags
 * @width: get width of it
 * @precision: Precision
 * @size: size specifier of it
 * Return: No of chars that are printed
 */
int output_octal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * output_hexadecimal - Prints hexadecimal
 * @types: Lista of arguments
 * @buffer: Buffer arr to handle print
 * @flags: gets active flags
 * @width: get width of it
 * @precision: Precision
 * @size: Size
 * Return: No. of chars printed
 */

int output_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (output_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * output_hexa_upper - Prints num in upper hexadecimal
 * @types: List a of args
 * @buffer: Buffer arr to handle print
 * @flags: gets active flags
 * @width: get width of it
 * @precision: Precision
 * @size: Size
 * Return: No of chars printed
 */

int output_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (output_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * output_hexa - return a hexadecimal number in lower or upper of pritn hexa
 * @types: Listof arguments of pritn hexa
 * @map_to: Array of values to map the number to of pritn hexa
 * @buffer: Buffer array to handle print of pritn hexa
 * @flags: get active flags of pritn hexa
 * @flag_ch: get active flags of pritn hexa
 * @width: cal width of pritn hexa
 * @precision: precision  of pritn hexa
 * @size: Size \ of pritn hexa
 * @size: Size  of pritn hexa
 * Return: No of chars printed of pritn hexa
 */

int output_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
