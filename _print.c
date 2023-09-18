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
    va_list arguments;
    va_start(arguments, format);


    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            if (*format == 'c')
            {
            char character = va_arg(arguments, int);
            _putchar(character);
            charlength++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(arguments, char *);
                if (str != NULL)
                {
                    int len = str_len(str);
                    write(1, str, len);
                    charlength += len;
                }
                else
                {
                    write(1, "null", 4);
                    charlength = 4;
                }
            
            }
            else if (*format == '%')
            {
                _putchar('%');
                charlength++;
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