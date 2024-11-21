#include <stdio.h>
#include <stdlib.h>

int find(int str[], int N) {
    int i = 0, x = 0;

    for (i = 1; i <= N; ++i) {
        x = x ^ i;
    }

    for (i = 0; i < N - 1; ++i) {
        x = x ^ str[i];
    }

    printf("%d", x);
}

int main() {
    int N = 0, i = 0;

    scanf("%d", &N);

    int* str = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N - 1; ++i) {
        int x = 0;
        scanf("%d", &x);
        str[i] = x;
    }

    find(str, N);
    free(str);
}