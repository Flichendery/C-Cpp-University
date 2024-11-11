#include <stdio.h>
#ifndef CALC2_H
#define CALC2_H

int binaryToDecimal(const char *binary) {
    int decimal = 0;
    while (*binary) {
        decimal = (decimal << 1) + (*binary++ - '0');
    }
    return decimal;
}

void decimalToBinary(int n, char *binary) {
    if (n == 0) {
        binary[0] = '0';
        binary[1] = '\0';
        return;
    }

    int index = 0;
    while (n > 0) {
        binary[index++] = (n % 2) + '0';
        n /= 2;
    }
    
    binary[index] = '\0';
    
    for (int i = 0; i < index / 2; i++) {
        char temp = binary[i];
        binary[i] = binary[index - 1 - i];
        binary[index - 1 - i] = temp;
    }
}

int calculate(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    } else if (op == '-') {
        return a - b;
    } else if (op == '<') {
        return (a << b);
    } else if (op == '>') {
        return a >> b;
    }
    return 0;
}

#endif