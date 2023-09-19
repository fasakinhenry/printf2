#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

/**
 * struct chk - This struct will be used to filter which print
 * function for i,c,s,d,x,X,o,p,u
 * @opt: % format specifier to use
 * @opt_func: function pointer to select the correct printer
 */

typedef struct chk
{
	char opt;
	void (*opt_func)(va_list arguments, int *printed_chars);
} checkForm;

int _putchar(char c);
int str_len(const char *s);
int print_char(va_list arguments);
int print_string(va_list arguments);
int _printf(const char *format, ...);

#endif
