#include "main.h"

/**
 * output_unsigned - Prints an unsigned num immediately
 * @types: Arguments listings
 * @buffer: Print handling Buffer arr
 * @flags: Active flags calculator
 * @width: helps to get width
 * @precision: Specifies precision
 * @size: specifies sizes
 *
 * Return: Gives number of chars printed
 */

int output_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int a_num = va_arg(types, unsigned long int);

	a_num = convert_size_unsgnd(a_num, size);
	if (a_num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (a_num > 0)
	{
		buffer[a--] = (a_num % 10) + '0';
		a_num /= 10;
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}


/**
 * output_octal - Prints an unsigned number in octal notation
 * @types: Arguments listing
 * @buffer: Print handling buffer array
 * @flags: gets active flags
 * @width: get width of it
 * @precision: This specifies precision
 * @size: The specifies size
 *
 * Return: No of chars that are printed
 */
int output_octal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int a_num = va_arg(types, unsigned long int);
	unsigned long int init_num = a_num;

	UNUSED(width);
	a_num = convert_size_unsgnd(a_num, size);
	if (a_num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (a_num > 0)
	{
		buffer[a--] = (a_num % 8) + '0';
		a_num /= 8;
	}
	if (flags & F_HASH && init_num != 0)
		buffer[a--] = '0';
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}


/**
 * output_hexadecimal - Prints hexadecimal
 * @types: Argumnts and listings
 * @buffer: Print handling buffer array
 * @flags: This gets active flags
 * @width: width calculator
 * @precision: This specifies precision
 * @size: This specifies size
 *
 * Return: No. of chars printed
 */

int output_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (output_hexa(types, "0123456789abcdef", buffer,
	flags, 'x', width, precision, size));
}

/**
 * output_hexa_upper - This prints num in upper hexadecimal
 * @types: Listings of a of args
 * @buffer: Print handling buffer array
 * @flags:Active flags calculator
 * @width: width get
 * @precision: This specifies precision
 * @size: This specifies size
 *
 * Return: No of chars printed
 */

int output_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	return (output_hexa(types, "0123456789ABCDEF", buffer,
	flags, 'X', width, precision, size));
}

/**
 * output_hexa - returns a hex number in lower or upper of pritn hexa
 * @types: This Listof arguments of pritn hexa
 * @map_to: Array of values to map the number to of pritn hexa
 * @buffer: Buffer array to handle print of pritn hexa
 * @flags: Active flag getting
 * @flag_ch: Active flags of print hex get
 * @width: cal width of pritn hexa
 * @precision: precision  of pritn hexa
 * @size: Size \ of pritn hexa
 * @size: Size  of pritn hexa
 * Return: No of chars printed of pritn hexa
 */

int output_hexa(va_list types, char map_to[], char buffer[],
int flags, char flag_ch, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int a_num = va_arg(types, unsigned long int);
	unsigned long int init_num = a_num;

	UNUSED(width);
	a_num = convert_size_unsgnd(a_num, size);

	if (a_num == 0)
		buffer[a--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (a_num > 0)
	{
		buffer[a--] = map_to[a_num % 16];
		a_num /= 16;
	}
	if (flags & F_HASH && init_num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}
	a++;
	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
