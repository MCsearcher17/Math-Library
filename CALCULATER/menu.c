#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

void display_menu(void) {
    int i ;
    char* menu[] = {
        "Addition", "Substraction", "Multipication", "Division", "Taking Sqaure",
        "Taking Cube", "Absoulte Value", "Absoulte Substraction", "Average",
        "Exponention", "Factorial", "Reverse", "Square Root", "e^x function",
        "Logartihm", "Natural Logarithm"
    };

    int SIZE = sizeof(menu) / sizeof(menu[0]);

    puts("**********************************************");
    puts("\t  BASIC CALCULATER");
    puts("**********************************************");
    puts("\t  MAIN MENU");
    puts("**********************************************");
    puts("Select the option you want to do");
    puts("**********************************************");

    for(i = 0; i < SIZE; i++) {
        printf("%d. %s\n", i + 1, menu[i]);
    }
}