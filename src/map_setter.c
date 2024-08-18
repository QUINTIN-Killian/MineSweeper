#include "../include/minesweeper.h"

void place_bombs(game_t *game)
{
    int x;
    int y;

    for (int i = 0; i < game->total_bombs; i++) {
        x = randint(0, game->width - 1);
        y = randint(0, game->height - 1);
        if (game->map[y][x] == 9) {
            i--;
            continue;
        }
        game->map[y][x] = 9;
    }
}

static int get_nb_bombs_around(game_t *game, int x, int y)
{
    int nb_bombs = 0;

    for (int ord = y - 1; ord <= y + 1; ord++) {
        for (int abs = x - 1; abs <= x + 1; abs++) {
            if (ord < 0 || ord >= game->height || abs < 0 ||
            abs >= game->width)
                continue;
            if (game->map[ord][abs] == 9)
                nb_bombs++;
        }
    }
    return nb_bombs;
}

void set_map_values(game_t *game)
{
    for (int y = 0; y < game->height; y++)
        for (int x = 0; x < game->width; x++)
            if (game->map[y][x] != 9)
                game->map[y][x] = get_nb_bombs_around(game, x, y);
}
