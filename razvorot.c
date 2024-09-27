#include <stdio.h>

int main() {

    char arr[100];
    int count = 0;
    char c;

    while (count < 100 && (c = getchar()) != EOF) {
        arr[count] = c;
        count++;
    }

    for (int i = count - 1; i >= 0; i--) {
        putchar(arr[i]);
    }
}