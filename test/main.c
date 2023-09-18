#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    
    
    printf("Let's try to printf a simple sentence.\n");
    _printf("Let's try to printf a simple sentence.\n");

    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "hello world");
    printf("String:[%s]\n", "Hello world");

     _printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");
    return (0);
}