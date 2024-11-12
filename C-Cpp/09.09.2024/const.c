#include <stdio.h>
#define LOWER 0
#define UPPER 50055
#define STEP 120

int main()
{
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf ("%3d %6.2f\n", fahr, (5.0/9.0) * (fahr - 32));
}