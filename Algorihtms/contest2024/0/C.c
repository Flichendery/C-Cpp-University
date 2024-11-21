#include <stdio.h>
#include <stdlib.h>

int main() {
    int N = 0, i = 0, j = 0;
    
    scanf("%d", &N);

    int* str1 = (int*)malloc(N * sizeof(int));

    int* str2 = (int*)malloc(N * sizeof(int));

    for (int i = 0; i < N; i++) {
        scanf("%d", &str1[i]);
    }

    for (i = N - 1, j = 0; i >= 0; i--, ++j) {
            str2[j] = str1[i];
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", str2[i]);
    }

    free(str1);
    free(str2);
}
