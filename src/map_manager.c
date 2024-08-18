#include "../include/minesweeper.h"

void create_map(game_t *game)
{
    game->map = malloc(sizeof(int *) * (game->height + 1));

    for (int i = 0; i < game->height; i++) {
        game->map[i] = malloc(sizeof(int) * (game->width + 1));
        game->map[i][game->width] = -1;
        for (int j = 0; j < game->width; j++)
            game->map[i][j] = 0;
    }
    game->map[game->height] = NULL;
}

void print_map(game_t *game)
{
    if (game->map == NULL) {
        mini_fdprintf(2, "NULL map.\n");
        return;
    }
    for (int i = 0; game->map[i] != NULL; i++) {
        for (int j = 0; game->map[i][j] != -1; j++) {
            mini_printf("%d ", game->map[i][j]);
        }
        mini_printf("\n");
    }
}

void destroy_map(game_t *game)
{
    if (game->map == NULL)
        return;
    for (int i = 0; game->map[i] != NULL; i++)
        free(game->map[i]);
    free(game->map);
}
