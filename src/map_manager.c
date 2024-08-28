#include "../include/minesweeper.h"

void create_map(minesweeper_t *minesweeper)
{
    minesweeper->map = malloc(sizeof(int *) * (minesweeper->height + 1));

    for (int i = 0; i < minesweeper->height; i++) {
        minesweeper->map[i] = malloc(sizeof(int) * (minesweeper->width + 1));
        minesweeper->map[i][minesweeper->width] = -1;
        for (int j = 0; j < minesweeper->width; j++)
            minesweeper->map[i][j] = 0;
    }
    minesweeper->map[minesweeper->height] = NULL;
}

void print_map(minesweeper_t *minesweeper)
{
    if (minesweeper->map == NULL) {
        mini_fdprintf(2, "NULL map.\n");
        return;
    }
    for (int i = 0; minesweeper->map[i] != NULL; i++) {
        for (int j = 0; minesweeper->map[i][j] != -1; j++) {
            mini_printf("%d ", minesweeper->map[i][j]);
        }
        mini_printf("\n");
    }
}

void destroy_map(minesweeper_t *minesweeper)
{
    if (minesweeper->map == NULL)
        return;
    for (int i = 0; minesweeper->map[i] != NULL; i++)
        free(minesweeper->map[i]);
    free(minesweeper->map);
}
