#include "main.h"
/**
 * print_number - prints a number
 * @num: num to be printed
 * @count: count
 * Return: num
 */
int print_number(long num, int count)
{
	if (num < 0)
	{
		_putchar('-');
		count++;
		num = num * -1;
	}
	if (num / 10)
	{
		count = print_number(num / 10, count);
	}
	_putchar(num % 10 + '0');
	return (count + 1);
}