#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0, M = 0, i = 0, j = 0;

    scanf("%d %d", &N, &M);

    long long** str = (long long**)malloc(N * sizeof(long long*));

    for (i = 0; i < N; i++) {
        str[i] = (long long*)malloc(M * sizeof(long long));
    }

    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            scanf("%ld", &str[i][j]);
        }
    }

    for (i = 0; i < N; ++i) {
        long long x = 0;
        for (j = 0; j < M; ++j) {
            x = x + str[i][j];
        }
        printf ("%ld ", x);
    }

    printf ("\n");

    for (j = 0; j < M; ++j) {
        long long x = 0;
        for (i = 0; i < N; ++i) {
            x = x + str[i][j];
        }
        printf ("%ld ", x);
    }
}