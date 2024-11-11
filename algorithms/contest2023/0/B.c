#include <stdio.h>
#include <stdlib.h>

void sort(int array[], int maximum) {
    int i = 0;
    for(i = 0; i < maximum; i++) {

    }
}

int main() {
    int maximum, i = 0;

    scanf("%d", &maximum);

    int* array = (int*)malloc(maximum * sizeof(int));
    int* bucket = (int*)malloc(maximum * sizeof(int));

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

// Not done yet :p