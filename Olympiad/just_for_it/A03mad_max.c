#include <stdio.h>
#include <stdlib.h>

int find(int array[], int N) {
    int max = -1;
    int i = 0;
    if (N > 1) {
        for (i = 0; i < N - 1; ++i) {
            if ((array[i] >= array[i + 1] && array[i] > max)) {
                max = array[i];
            }
            else {
                if (array[i] <= array[i + 1] && array[i + 1] > max) {
                    max = array[i + 1];
                }
            }
        }

        int i, c = 0;
        for (i = 0; i < N; ++i) {
            if (array[i] == max) {
                c += 1;
            }
        }

        printf("%d %d", max, c);
    }

    else {
        printf("%d 1", array[0]);
    }
}

int main() {
    int N, i = 0;

    scanf("%d", &N);

    int* array = (int*)malloc(N * sizeof(int));

    for (i = 0; i < N; ++i) {
        int x = 0;
        scanf("%d", &x);
        array[i] = x;
    }

    find(array, N);
    free(array);
}