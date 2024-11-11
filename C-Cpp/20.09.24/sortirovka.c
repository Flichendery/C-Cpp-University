#include <stdio.h>

int main() {

    char arr[100];
    int count = 0;
    char c, n;

    while (count < 100 && (c = getchar()) != EOF) {
        arr[count] = c;
        count++;
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                n = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = n;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        putchar(arr[i]);
    }
}