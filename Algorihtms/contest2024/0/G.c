#include <stdio.h>
#include <stdlib.h>

int find(int str1[], int str2[], int N, int C) {
    int i = 0, j = 0;

    for (j = 0; j < C * 2 - 1; ++j) {
        int x = str1[str2[j]];
        str1[str2[j]] = str1[str2[j + 1]];
        str1[str2[j + 1]] = x;
        j += 1;
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", str1[i]);
    }
}

int main() {
    int N = 0, C = 0, i = 0, j = 0;

    scanf("%d", &N);

    int* str1 = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; ++i) {
        long long x = 0;
        scanf("%ld", &x);
        str1[i] = x;
    }

    scanf("%d", &C);

    int* str2 = (int*)malloc(C * 3 * sizeof(int));

    for (i = 0; i < C; ++i) {
        for (j = 0; j < C * 3; ++j) {
            int x = 0;
            scanf("%d", &x)
        }
    }

    for (i = 0; i < C * 3; ++i) {
        printf("%d ", str2[i]);
    }
}