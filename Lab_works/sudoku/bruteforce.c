#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudoku_all.h"

// Функция сна (использование ifdef для кроссплатформенной работы)
#ifdef _WIN32
    #include <windows.h>
    void my_sleep(int milliseconds) {
        Sleep(milliseconds);
    }
#else
    #include <time.h>
    void my_sleep(int milliseconds) {
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    }
#endif

// Выбор случайной цифры при генерации поля
void shuffle_numbers(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = numbers[i];
        numbers[i] = numbers[j];
        numbers[j] = temp;
    }
}

// Брутфорс с рекурсией и сном
int bruteforce(SudokuGrid *grid, sudoku_size row, sudoku_size col) {
    if (row == (*grid).size) return 1;

    sudoku_size next_row = (col == (*grid).size - 1) ? row + 1 : row;
    sudoku_size next_col = (col + 1) % (*grid).size;

    int *cell = &(*(*((*grid).cells + row) + col));

    // Если ячейка содержит число игрока и оно неправильное — очистить
    if (*cell < 0 && !is_valid_move(grid, row, col, abs(*cell))) {
        *cell = 0;  // Удаляем число
    }

    // Если ячейка уже заполнена корректным числом — пропускаем её
    if (*cell != 0) {
        return bruteforce(grid, next_row, next_col);
    }

    // Перебираем возможные значения
    for (int num = 1; num <= (*grid).size; num++) {
        if (is_valid_move(grid, row, col, num)) {
            *cell = num;

            Position cursor = {row, col};
            clear_screen();
            display_grid(grid, cursor);
            my_sleep(10);

            if (bruteforce(grid, next_row, next_col)) {
                return 1;
            }

            *cell = 0;  // Откат
        }
    }
    return 0;
}

// Скрытый брутфорс, который создаёт поле, которое гарантировано можно решить
int brute_hide(SudokuGrid *grid, sudoku_size row, sudoku_size col) {
    if (row == (*grid).size) return 1;

    sudoku_size next_row = (col == (*grid).size - 1) ? row + 1 : row;
    sudoku_size next_col = (col + 1) % (*grid).size;

    if (*(*((*grid).cells + row) + col) != 0) {
        return brute_hide(grid, next_row, next_col);
    }

    int *numbers = (int *)malloc((*grid).size * sizeof(int));
    for (int i = 0; i < (*grid).size; i++) {
        numbers[i] = i + 1;
    }

    shuffle_numbers(numbers, (*grid).size);

    for (int i = 0; i < (*grid).size; i++) {
        int num = numbers[i];
        if (is_valid_move(grid, row, col, num)) {
            *(*((*grid).cells + row) + col) = num;

            if (brute_hide(grid, next_row, next_col)) {
                free(numbers);
                return 1;
            }

            *(*((*grid).cells + row) + col) = 0;
        }
    }

    free(numbers);
    return 0;
}

// Инициализация брутфорса
int run_bruteforce(SudokuGrid *grid) {
    if (bruteforce(grid, 0, 0)) {
        clear_screen();
        printf(YELLOW "Solution by brute-force:\n" RESET);
        Position cursor = {-1, -1};
        display_grid(grid, cursor);
        return 1;
    } else {
        printf(YELLOW "No solution exists.\n" RESET); // На случай непредвиденной ошибки :D
        return 0;
    }
}