#include "main.h"
#include <stdarg.h>

void print_char(va_list arguments, int *printed_chars)
{
    char character = va_arg(arguments, int); 
    _putchar(character);
    (*printed_chars)++;
}