#include "main.h"

/**
 * get_flags - Gets all the flags
 * @format: Strung to print args
 * @i: parameter parsed
 * Return: all flags
 */

int get_flags(const char *format, int *i)
{
	int k, current_i;
	int flags = 0;
	const char FLAG_CHARACTER[] = {'+', '-', '0', ' ', '#', '\0'};
	const int FLAG_ARRAYS[] = {F_PLUS, F_MINUS, F_ZERO, F_SPACE, F_HASH,
		0};
	for (current_i = *i + 1; format[current_i] != '\0'; current_i++)
	{
		for (k = 0; FLAG_CHARACTER[k] != '\0'; k++)
			if (format[current_i] == FLAG_CHARACTER[k])
			{
				flags |= FLAG_ARRAYS[k];
				break;
			}
		if (FLAG_CHARACTER[k] == 0)
			break;
	}
	*i = current_i - 1;
	return (flags);
}
