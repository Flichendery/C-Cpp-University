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
    int N = 0, C = 0, i = 0;

    scanf("%d %d", &N, &C);

    int* str1 = (int*)malloc(N * sizeof(int));

    int* str2 = (int*)malloc(C * 2 * sizeof(int));

    for (i = 0; i < N; ++i) {
        int x = 0;
        scanf("%d", &x);
        str1[i] = x;
    }

    if (N > 1) {
        if (C > 0) {
            for (i = 0; i < C; ++i) {
                int x1 = 0, x2 = 0;
                scanf("%d %d", &x1, &x2);
                str2[i * 2] = x1, str2[i * 2 + 1] = x2;
            }

            find(str1, str2, N, C);
        }

        else {
            for (i = 0; i < N; ++i) {
                printf("%d ", str1[i]);
            }
        }
    }

    else {
        for (i = 0; i < C; ++i) {
            int x1 = 0, x2 = 0;
            scanf("%d %d", &x1, &x2);
        }

        printf("%d", str1[0]);
    }

    free(str1);
    free(str2);
}