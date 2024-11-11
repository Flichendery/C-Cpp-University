#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    
    int *ptr = arr;

    for (int i = 0; i < 5; i++) {
        printf("%d ", *(ptr + i));
    }
    printf("\n");

    ptr = &arr[4];
    for (int i = 0; i < 5; i++) {
        printf("%d ", *ptr);
        ptr--; 
    }
    printf("\n");
}