#include <stdio.h>

int main() {
    int N, M;

    scanf("%d %d", &N, &M);
    
    if (N > 100 || M > 100) {
        return 1;
    }

    int matrix[100][100];

    int seed = 123;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            seed = (seed * 1103515245 + 12345) & 0x7fffffff;
            matrix[i][j] = seed % 100;
        }
    }


    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%2d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }


    while (1) {
        int i, j, newValue;
        
        scanf("%d %d %d", &i, &j, &newValue);
        
        if (i >= 0 && i < N && j >= 0 && j < M) {
            *(*(matrix + i) + j) = newValue;
            

            for (int i = 0; i < N; i++) {
                for (int j = 0; j < M; j++) {
                    printf("%2d ", *(*(matrix + i) + j));
                }
                printf("\n");
            }
        } else {
            printf("error");
        }
    }
}