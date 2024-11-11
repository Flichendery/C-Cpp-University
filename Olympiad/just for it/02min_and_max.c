#include <stdio.h>
#include <stdlib.h>

int find(int array[], int N) {
    int i = 0;
    int max = -1;
    int min = 1001;

    if (N > 1) {
        for (i = 0; i < N - 1; ++i) {
            if (array[i] >= array [i + 1] && array[i] > max) {
                max = array[i];
            }
            else {
                if (array[i] <= array [i + 1] && array[i + 1] > max) {
                    max = array[i + 1];
                }
            }
            if (array[i] <= array [i + 1] && array[i] < min) {
                min = array[i];
            }
            else {
                if (array[i] >= array [i + 1] && array[i + 1] < min) {
                    min = array[i + 1];
                }
            }
        }
        printf("%d %d", min, max);
    }
    
    else {
        printf("%d %d", array[0], array[0]);
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
}