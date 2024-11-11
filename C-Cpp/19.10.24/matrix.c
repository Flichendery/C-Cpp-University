#include <stdio.h>
#include <stdlib.h>

int** createMatrix(int rows, int cols);
void printMatrix(int** matrix, int rows, int cols);
void sortRow(int** matrix, int row, int cols, int (*compare)(int, int));
void sortColumn(int** matrix, int rows, int col, int (*compare)(int, int));
int increase(int a, int b);
int decrease(int a, int b);
void swapRows(int** matrix, int row1, int row2, int cols);

int main(int argc, char** argv) {
    int rows = atoi(*(argv + 1));
    int cols = atoi(*(argv + 2));

    int** matrix = createMatrix(rows, cols);

    printf("Original matrix:\n");
    printMatrix(matrix, rows, cols);

    int choice, index;
    printf("1 - row, 2 - column:");
    scanf("%d", &choice);

    printf("Index to sort:");
    scanf("%d", &index);
    index -= 1;

    printf("1 - increase, 2 - decrease:");
    int sortType;
    scanf("%d", &sortType);

    int (*compare)(int, int);
    if (sortType == 1) {
        compare = increase;
    } else {
        compare = decrease;
    }

    if (choice == 1) {
        sortRow(matrix, index, cols, compare);
    } else if (choice == 2) {
        sortColumn(matrix, rows, index, compare);
    }

    printf("Sorted matrix:\n");
    printMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++) {
        free(*(matrix + i));
    }
    free(matrix);

    return 0;
}

int** createMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        *(matrix + i) = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(matrix + i) + j) = rand() % 101;
        }
    }

    return matrix;
}

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", *(*(matrix + i) + j));
        }
        printf("\n");
    }
}

void swapRows(int** matrix, int row1, int row2, int cols) {
    for (int i = 0; i < cols; i++) {
        int temp = *(*(matrix + row1) + i);
        *(*(matrix + row1) + i) = *(*(matrix + row2) + i);
        *(*(matrix + row2) + i) = temp;
    }
}

void swapColumn(int** matrix, int col1, int col2, int rows) {
    for (int i = 0; i < rows; i++) {
        int temp = *(*(matrix + i) + col1);
        *(*(matrix + i) + col1) = *(*(matrix + i) + col2);
        *(*(matrix + i) + col2) = temp;
    }
}

void sortRow(int** matrix, int row, int cols, int (*compare)(int, int)) {
    for (int i = 0; i < cols - 1; i++) {
        for (int j = 0; j < cols - i - 1; j++) {
            if (compare(*(*(matrix + row) + j), *(*(matrix + row) + j + 1))) {
                swapColumn(matrix, j, j + 1, cols);
            }
        }
    }
}

void sortColumn(int** matrix, int rows, int col, int (*compare)(int, int)) {
    for (int i = 0; i < rows - 1; i++) {
        for (int j = 0; j < rows - i - 1; j++) {
            if (compare(*(*(matrix + j) + col), *(*(matrix + j + 1) + col))) {
                swapRows(matrix, j, j + 1, rows);
            }
        }
    }
}

int increase(int a, int b) {
    return a > b;
}

int decrease(int a, int b) {
    return a < b;
}