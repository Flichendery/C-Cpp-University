#include <stdio.h>
#include <string.h>

int main() {
    int count;
    scanf("%d", &count);
    
    int numbers[1000];
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%d", numbers[i]);
        if (i > 0) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}