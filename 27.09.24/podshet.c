#include <stdio.h>

int main() {

    int count[128] = {0}; 

    char c;

    while ((c = getchar()) != EOF) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
        if (c >= 0 && c < 128) {
            count[c]++;
        }
    }

    for (int i = 0; i < 128; i++) {
        if (count[i] > 0) {
            printf("%c: %d\n", i, count[i]);
        }
    }
}
