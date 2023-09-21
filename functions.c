#include "main.h"
/**
 * output_char - outs a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: cal active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int output_char(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	char ch = va_arg(types, int);

	return (handle_write_char(ch, buffer, flags, width, precision,
	size));
}
/**
 * output_string - it Prints a string
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: cal active flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: no of chars printed
 */
int output_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int leng = 0, il;
	char *strg = va_arg(types, char *);

	UNUSED(precision);
	UNUSED(size);
	UNUSED(buffer);
	UNUSED(width);
	UNUSED(flags);

	if (strg == NULL)
	{
		strg = "(null)";
		if (precision >= 6)
			strg = " ";
	}
	while (strg[leng] != '\0')
		leng++;
	if (precision >= 0 && precision < leng)
		leng = precision;
	if (width > leng)
	{
		if (flags & F_MINUS)
		{
			write(1, &strg[0], leng);
			for (il = width - leng; il > 0; il--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (il = width - leng; il > 0; il--)
				write(1, " ", 1);
			write(1, &strg[0], leng);
			return (width);
		}
	}
	return (write(1, strg, leng));
}

/**
 * output_percent - it Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: cal active flags
 * @width: gets width.
 * @precision: Precision
 * @size: Size
 *
 * Return: no of chars printed
 */
int output_percent(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * output_int - it Print int
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: cal active flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of chars printed
 */
int output_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int il = BUFF_SIZE - 2;
	int is_negative = 0;
	long int no = va_arg(types, long int);
	unsigned long int a_num;

	no = convert_size_number(no, size);

	if (no == 0)
		buffer[il--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	a_num = (unsigned long int)no;
	if (no < 0)
	{
		a_num = (unsigned long int)((-1) * no);
		is_negative = 1;
	}
	while (a_num > 0)
	{
		buffer[il--] = (a_num % 10) + '0';
		a_num /= 10;
	}
	il++;
	return (write_number(is_negative, il, buffer, flags, width,
				precision, size));
}


/**
 * output_binary - Prints an unsigned number
 * @types: Arguments listings
 * @buffer: Buffer array for print handling
 * @flags: Active flags calculator
 * @width: This gets the width
 * @precision: This specifies precision
 * @size: This specifies size
 *
 * Return: Numbers of char printed.
 */

int output_binary(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	unsigned int n;
	unsigned int il;
	unsigned int em;
	unsigned int sums;
	unsigned int b[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	n = va_arg(types, unsigned int);
	em = 2147483648U;
	b[0] = n / em;
	for (il = 1; il < 32; il++)
	{
		em /= 2;
		b[il] = (n / em) % 2;
	}
	for (il = 0, sums = 0, count = 0; il < 32; il++)
	{
		sums += b[il];
		if (sums || il == 31)
		{
			char z = '0' + b[il];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
