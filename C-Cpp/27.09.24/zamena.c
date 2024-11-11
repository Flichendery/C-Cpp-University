#include <stdio.h>

int main()
{
    int x = 15;
    int *xPtr = &x;

    *xPtr = 25;

    printf("%x\n", xPtr);
    printf("%d\n", *xPtr);
    printf("%d\n", x);
}