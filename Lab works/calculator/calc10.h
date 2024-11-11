#include <stdio.h>
#ifndef CALC10_H
#define CALC10_H

int plus(int a, int b) {
    return a + b;
}

int minus(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

int calculate(int a, int b, char op) {
    if (op == '+') {
        return plus(a, b);
    } else if (op == '-') {
        return minus(a, b);
    } else if (op == '*') {
        return multiply(a, b);
    } else if (op == '/') {
        return divide(a, b);
    }
    return 0;
}

#endif