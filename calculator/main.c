#include <stdio.h>
#include <stdlib.h>

#define SYSTEM 2

#if SYSTEM == 10
    #include "calc10.h"
#elif SYSTEM == 2
    #include "calc2.h"
#endif

int main() {
    #if SYSTEM == 10
        int a, b;
        char op;
        scanf("%d %c %d", &a, &op, &b);
        
        int result = calculate(a, b, op);
        printf("%d\n", result);
    
    #elif SYSTEM == 2
        char num1[33], num2[33], resultBinary[33];
        char op;
        int a, b;

        scanf("%s %c %s", num1, &op, num2);
        
        a = binaryToDecimal(num1);
        b = binaryToDecimal(num2);
        
        int result = calculate(a, b, op);
        decimalToBinary(result, resultBinary);

        printf("%s\n", resultBinary);
    #endif

    return 0;
}