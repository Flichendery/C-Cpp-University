#include <stdio.h>

int main()
{
    int x1 = 15;
    int *x1Ptr = &x1;
    float x2 = 7.12;
    float *x2Ptr = &x2;

    printf("%x\n", x1Ptr);
    printf("%x\n", x2Ptr);
    printf("%d\n", *x1Ptr);
    printf("%d\n", *x2Ptr);
}