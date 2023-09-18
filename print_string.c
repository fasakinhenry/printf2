#include "main.h"
#include <unistd.h>
#include <stdarg.h>

void print_string(va_list args, int *printed_chars) {
    char *str = va_arg(args, char *);
    if (str != NULL) {
        int len = str_len(str);
        write(1, str, len);
        (*printed_chars) += len;
    } else {
        write(1, "(null)", 6);
        (*printed_chars) += 6;
    }
}