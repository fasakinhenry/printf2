#ifndef MAIN_H
#define MAIN_H

#include "stdlib.h"
#include "stdarg.h"

/** typedef struct formatCheck
 *  {
 *     char opt;
 *     char (*opt_func)(int, int);
 * }checkForm;
 */

int _putchar(char c);
int str_len (const char *s);
int _printf(const char *format, ...);

#endif