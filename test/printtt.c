#include <stdio.h>
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>
 #include <stdarg.h>
 
 int _putchar(char c)
 {
  write(1, &c, 1);
  return 1;
 }
 int print_number(long num, int count)
 {
   if (num < 0)
   {
    _putchar('-');
    count++;
    num = num * -1;
   }
  if (num/10)
  {
  count = print_number(num/10, count);
  }
  _putchar(num%10 + '0');
  return (count + 1);
 }
 int c_handler(va_list arg)
 {
   int count;
   char get_char = va_arg(arg, int);
  count = _putchar(get_char);
  return count; 
 }
  int d_handler(va_list arg)
 {
   int count;
   
   int val = va_arg(arg, int);
   
   count = print_number(val, 0);
   
   return count;
 }
int s_handler(va_list arg)
{
        int count = 0;
        char *ptr = va_arg(arg, char *);
        if (ptr == NULL)
        {
                ptr = "(null)";
        }
        while (*ptr)
        {
                count += _putchar(*ptr);
                ptr++;
        }

        return count;
}
 
 int (*selector(char str))(va_list arg)
 { 
   if (str == 'c')
   {
    return &c_handler;
   }
   else if (str == 'd')
   {
    return &d_handler; 
   }
   else if (str == 's')
   {
     return &s_handler;
   }
return 0;
 }

int demoprintf(const char *format, ...)
{
  va_list args;
  va_start(args, format);
  int i;
  int ncount = 0;
  
  if (format == NULL)
  {
    return -1;
  }
  
  for (i = 0; format[i] != '\0'; i++)
  {
    if (format[i] == '%')
    {
      i++;
      if (format[i] == 'c' || format[i] == 'd' || format[i] == 's')
      {
        ncount += selector(format[i])(args);
      }
      else
      {
       ncount += _putchar('%');
       //ncount += _putchar(format[i]);
        continue;
      } 
    }
    else
    {
     ncount += _putchar(format[i]); 
    } 
  }

return ncount;
}


int main(void)
{
  int len1 = printf("prog lang: %c %s %c %s\n", 'C', "hello world", 'F', "YO");
  int len2 = demoprintf("prog lang: %c %s %c %s\n", 'C', "hello world", 'F', "YO");

  
 
 printf("%d = %d", len1, len2);
  
}