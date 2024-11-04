#include <stdio.h>
#include <stdlib.h>

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


int main() {
    char num1[33], num2[33];
    char op;
    int a, b;

    scanf("%s %c %s", num1, &op, num2);
    
    a = binaryToDecimal(num1);
    b = binaryToDecimal(num2);

    int result = calculate(a, b, op);

    char resultBinary[33];
    decimalToBinary(result, resultBinary);

    printf("%s\n", resultBinary);
    return 0;
}