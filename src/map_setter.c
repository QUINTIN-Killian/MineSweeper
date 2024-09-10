#include "../include/minesweeper.h"

void place_bombs(minesweeper_t *minesweeper)
{
    int x;
    int y;

    for (int i = 0; i < minesweeper->total_bombs; i++) {
        x = randint(0, minesweeper->width - 1);
        y = randint(0, minesweeper->height - 1);
        if (minesweeper->map[y][x] == 9) {
            i--;
            continue;
        }
        minesweeper->map[y][x] = 9;
    }
}

static int get_nb_bombs_around(minesweeper_t *minesweeper, int x, int y)
{
    int nb_bombs = 0;

    for (int ord = y - 1; ord <= y + 1; ord++) {
        for (int abs = x - 1; abs <= x + 1; abs++) {
            if (ord < 0 || ord >= minesweeper->height || abs < 0 ||
            abs >= minesweeper->width)
                continue;
            if (minesweeper->map[ord][abs] == 9)
                nb_bombs++;
        }
    }
    return nb_bombs;
}

void set_map_values(minesweeper_t *minesweeper)
{
    for (int y = 0; y < minesweeper->height; y++)
        for (int x = 0; x < minesweeper->width; x++)
            if (minesweeper->map[y][x] != 9)
                minesweeper->map[y][x] = get_nb_bombs_around(minesweeper,
                x, y);
}

void reset_map(minesweeper_t *minesweeper)
{
    for (int y = 0; y < minesweeper->height; y++)
        for (int x = 0; x < minesweeper->width; x++)
            minesweeper->map[y][x] = 0;
    place_bombs(minesweeper);
    set_map_values(minesweeper);
    print_map(minesweeper);
}
