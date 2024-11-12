#include <stdio.h>

int main () {
    char c;
    int space = 0;
    while ((c = getchar()) != EOF) 
    {
        if (c == ' ') space++;              
        if (space <= 1 ) putchar (c);
        if (c != ' ' && space > 1) putchar (c);
        if (c != ' ') space=0;
    }
}