#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
/* SIZE */
#define S_LONG 2
#define S_SHORT 1
/* FLAG */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16
/**
* struct fmt -  op
*
* @fmt: spec
* @fn: func
*/
struct fmt
{
char fmt;
int (*fn)(va_list, char[], int, int, int, int);
};
/**
* typedef struct fmt fmt_t - op
*
* @fmt: frmt
* @fm_t: func to be called
*/

typedef struct fmt fmt_t;
int _printf(const char *format, ...);
int handles_printing(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int
size);
/*FUNCTIONS*/
int output_char(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_string(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_percent(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* Funcs that print nums */
int output_int(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_unsigned(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_octal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_hexadecimal(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_hexa_upper(va_list types, char buffer[],
int flags, int width, int precision, int size);
int output_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int
size);
/* Func that print non printable chars */
int output_non_printable(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* Funcs]s that can deal with other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_prcn(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
/* Funcs to print mem address */
int output_pointer(va_list types, char buffer[],
int flags, int width, int precision, int size);
/*Func to print a string in rot 13*/
int output_rot13string(va_list types, char buffer[],
int flags, int width, int precision, int size);
/*Func to print string in reverse*/
int output_reverse(va_list types, char buffer[],
int flags, int width, int precision, int size);
/* width  */
int handle_write_char(char c, char buffer[],
int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
int flags, int width, int precision, int size);
int write_unsgnd(int is_negative, int ind,
char buffer[],
int flags, int width, int precision, int size);
int write_pointer(char buffer[], int ind, int length,
int width, int flags, char padd, char extra_c, int padd_start);
int write_num(int ind, char bff[], int flags, int width, int precision,
int length, char padd, char extra_c);

int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

#endif
