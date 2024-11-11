#include <stdio.h>
#include <stdlib.h>

int sort(int array[], int maximum) {
    int i, j, k;

    if (maximum > 3 && maximum != 4) {
        for (i = 0; i < (maximum / 2); ++i) {
            j = i;
            while (array[j] > array[j + 1] && j < (maximum / 2)) {
                int k = array[j];
                array[j] = array[j + 1];
                array[j + 1] = k;
                j -= 1;
            }
        }
        
        for (i = (maximum / 2) + 1; i < maximum; ++i) {
            j = i;
            while (j < maximum - 1 && array[j] < array[j + 1]) {
                k = array[j];
                array[j] = array[j + 1];
                array[j + 1] = k;
                j += 1;
            }
        }
    }

    else {
        if (maximum > 1) {
            for (i = 0; i < (maximum / 2); ++i) {
                j = i;
                while (j < (maximum / 2) - 1 && array[j] > array[j + 1]) {
                    k = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = k;
                    j += 1;
                }
            }
            
            for (i = (maximum / 2); i < maximum; ++i) {
                j = i;
                while (j < maximum - 1 && array[j] < array[j + 1]) {
                    k = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = k;
                    j += 1;
                }
            }            
        }

        else {
            return 0;
        }
    }
}

int main() {
    int maximum, i = 0;

    scanf("%d", &maximum);

    int* array = (int*)malloc(maximum * sizeof(int));

    for(i = 0; i < maximum; i++) {
        int x = 0;
        scanf("%d", &x);
        array[i] = x;
    }
    
    sort(array, maximum);
    
    i = 0;

    for(i = 0; i < maximum; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}