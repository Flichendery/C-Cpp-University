#include <stdio.h>
#include <stdlib.h>

int find(int str1[], int str2[], int N) {
    int i = 0;

    int* str3 = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; ++i) {
        if (str1[i] > str2[i]) str3[i] = str2[i];
        if (str1[i] < str2[i]) str3[i] = str1[i];
        if (str1[i] == str2[i]) str3[i] = str2[i];
    }

    for (i = 0; i < N; ++i) {
        printf("%d ", str3[i]);
    }
    free(str3);
}

int main() {
    int N = 0, i = 0;

    scanf("%d", &N);

    int* str1 = (int*)malloc(N * sizeof(int));

    int* str2 = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; ++i) {
        int x = 0;
        scanf("%d", &x);
        str1[i] = x;
    }

    for (i = 0; i < N; ++i) {
        int x = 0;
        scanf("%d", &x);
        str2[i] = x;
    }

    find(str1, str2, N);
    
    free(str1);
    free(str2);
}