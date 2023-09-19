#include <limits.h>
#include <stdio.h>
#include "main.h"

int main(void)
{
    char *null_string = NULL;
    int len1;
    int len2;
    
    printf("Let's try to printf a simple sentence.\n");
    _printf("Let's try to printf a simple sentence.\n");

    len1 = _printf("Character:[%c]\n", 'H');
    len2 = printf("Character:[%c]\n", 'H');

    _printf("String:[%s]\n", "Hello world");
     printf("String:[%s]\n", "Hello world");

    _printf("Percent:[%%]\n");
    printf("Percent:[%%]\n");
    printf("Len:[%d] [%d]\n", len2, len1);


    _printf("Test case 1: Character: %c\n", 'A');

    _printf("Test case 2: String: %s\n", "Hello, World!");
    _printf("Test case 2: String: %d hhh %i\n", len1, len2);

    _printf("Test case 3: Percent Sign: %%%%%%\n");

    _printf("Test case 5: NULL String: %s\n", null_string);
    _printf("Test case 4: Multiple Format Specifiers: %s %c %% %c %s\n","Bonjour!", 'B', 'A', "Hi");
    _printf("Test case 4: Multiple Format Specifiers: %c %s %% %c %s\n", 'B', "Guten Tag!", 'C', "Bonjour!");
    

   

    return (0);
}