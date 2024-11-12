#include <stdio.h>
#include <stdlib.h>

void sort(int str[], int maximum) {
    int i;
    for (int i = 0; i < maximum; ++i) {
        int j = i;
        while (str[j] > str[j + 1] && j < maximum) {
            int k = str[j];
            str[j] = str[j + 1];
            str[j + 1] = k;
            j -= 1;
        }
    }
}

int main() {
    int maximum, i = 0;

    scanf("%d", &maximum);

    int* str = (int*)malloc(maximum * sizeof(int));
    
    for(i = 0; i < maximum; i++) {
        int x = 0;
        scanf("%d", &x);
        str[i] = x;
    }
    
    sort(str, maximum);

    i = 0;

    for(i = 0; i < maximum; i ++) {
        printf("%d ", str[i]);
    }
    printf("\n");
    free(str); 
}