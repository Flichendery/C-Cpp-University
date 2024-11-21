#include <stdio.h>
#include <stdlib.h>

int find(int array[], int N) {
    int max1 = -1;
    int i = 0;
    if (N > 2) {
        for (i = 0; i < N - 1; ++i) {
            if ((array[i] >= array[i + 1] && array[i] > max1)) {
                max1 = array[i];
            }

            else {
                if (array[i] <= array[i + 1] && array[i + 1] > max1) {
                    max1 = array[i + 1];
                }
            }
        }

        int i, c = 0;
        for (i = 0; i < N; ++i) {
            if (array[i] == max1) {
                c += 1;
            }
        }

        if (c == 1) {
            int max2 = -1;

            for (i = 0; i < N - 1; ++i) {
                if ((array[i] > array[i + 1] && array[i] < max1 && array[i] > max2)) {
                    max2 = array[i];
                }

                else {
                    if (array[i] < array[i + 1] && array[i] < max1 && array[i] > max2) {
                        max2 = array[i];
                    }
                }
            }

            printf("%d", max2);

        }

        else {
            printf("%d", max1);
        }
    }

    else {
        if (N == 1) {
            printf("%d", -1);
        }
        
        else {
            for (i = 0; i < 2; ++i) {
                if (array[i] > array[i + 1]) {
                    printf("%d", array[i + 1]);
                    break;
                }

                else {
                    if (array[i] < array[i + 1]) {
                        printf("%d", array[i]);
                        break;
                    }

                    else {
                        printf("%d", array[i]);
                        break;
                    }
                }
            }
        }
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