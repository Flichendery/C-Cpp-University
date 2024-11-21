#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sudoku_all.h"
#include "bruteforce.c"
#include "game.c"
#include "sudoku.c"

// Определение BRUTEFORCE, если нужно чтобы работал именно он
#define BRUTEFORCE

// Инициализация всей игры
int main() {
    srand(time(NULL));
    SudokuGrid grid;
    Position cursor = {0, 0};
    GridSize size;

    // Выбор размера судоку
    printf("Sudoku size (4x4 or 9x9): ");
    int input;
    scanf("%d", &input);

    if (input == 4) {
        size = FOUR_BY_FOUR;
    } else if (input == 9) {
        size = NINE_BY_NINE;
    } else {
        printf("Invalid size. Defaulting to 9x9.\n");
        size = NINE_BY_NINE;
    }

    initialize_grid(&grid, size);
    generate_initial_grid(&grid);

    // Вывод сетки и выбор режима
    display_grid(&grid, cursor);

    // Использование директивы препроцессора для выбора режима
#ifdef BRUTEFORCE
    // Если определён BRUTEFORCE, запускаем его
    run_bruteforce(&grid);
#else
    start_game(&grid, cursor);
#endif

    free_grid(&grid);
    return 0;
}
