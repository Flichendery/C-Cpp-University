#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

int find(int str[], int N) {
    int i = 0, c = 0, count = 0;
    for (i = 0; i < N; ++i) {
        if (str[i] == 1) c += 1;
        if ((str[i] == 0 || i + 1 >= N) && c >= count && c > 0) count = c, c = 0;
        if ((str[i] == 0 || i + 1 >= N) && c < count) c = 0;
    }

    printf("%d", count);
}


int main() {
    int N = 0, i = 0;

    scanf("%d", &N);

    int* str = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; ++i) {
        int x = 0;
        scanf("%d", &x);
        str[i] = x;
    }

    find(str, N);
}