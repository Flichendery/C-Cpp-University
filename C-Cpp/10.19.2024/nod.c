#include <stdio.h>

int nod(int a, int b) {
    while (a && b) {
        if (a >= b) {
            a %= b;
        } else {
            b %= a;
        }
    }
    return a | b;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", nod(a, b));
}