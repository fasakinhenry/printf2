#ifndef MAIN_H
#define MAIN_H

#include "stdlib.h"
#include "stdarg.h"

typedef struct
{
    char opt;
    void (*opt_func)(va_list args, int *printed_chars);
}checkForm;
 

int _putchar(char c);
int str_len (const char *s);
void print_char(va_list arguments, int *printed_chars);
void print_string(va_list arguments, int *printed_chars);
int _printf(const char *format, ...);

#endif