#include <unistd.h>

/**
 * _putchar - writes character, c to stdout
 * @c: character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and err no is set appropriately.
 */

int _putchar(char c)
{
	write(1, &c, 1);
	return (1);
}
