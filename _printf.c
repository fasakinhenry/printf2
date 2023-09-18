#include "main.h"
#include <unistd.h>


/**
 * str_len - to get the length of a string
 * @s: string
 * Return: returns the length
*/

int str_len (const char *s)
{
    int len = 0;
    while (*s != '\0')
    {
        len++;
        s++;
    }
    return (len);
}

/**
 * _printf - printf function
 * @format - format specified
 * Return - formatted output
*/
int _printf(const char *format, ...)
{
    int charlength = 0;
            checkForm formatchk[] = {
                {'c', print_char},
                {'s', print_string}
            };
            int i;

    va_list arguments;
    va_start(arguments, format);


    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;


            for (i = 0; i < 2; i++)
            {
                if (*format == formatchk[i].opt)
                {
                    formatchk[i].opt_func(arguments, &charlength);
                    break;
                }
            }
 
        }
        else
        {
            _putchar(*format);
            charlength++;
        }
        format++;
    }

    va_end(arguments);
    return (charlength);
}