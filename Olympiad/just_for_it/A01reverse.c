#include <stdio.h>

int main() {
    int count;
    int numbers[1000];

    scanf("%d", &count);

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
}
