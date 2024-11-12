#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int main() {
    int str[SIZE];
    int i, j = 0;

    for (i = 0; i < SIZE; ++i) {
        int x = getchar();
        if (x == '\n') break;
        if (x == ' ') continue;
        str[i] = x - '0';
    }

    for (j = 0; j < i; ++j) {
        printf("%1d ", str[j]);
    }
}