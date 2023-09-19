#include "main.h"

int print_decimal(va_list arguments)
{
        int count;
        int val = va_arg(arguments, int);
        
        count = print_number(val, 0);
        
        return (count);
}