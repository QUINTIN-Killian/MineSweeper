#include "../include/minesweeper.h"

static void init(game_t *game)
{
    game->width = 19; //default : 19
    game->height = 26; //default : 26
    game->total_bombs = 99;
    game->bombs_left = 0;
    create_map(game);
    place_bombs(game);
    set_map_values(game);
    init_window(game);
    init_cursor(game);
}

static void destroy(game_t *game)
{
    destroy_window(game);
    destroy_map(game);
    destroy_cursor(game);
}

void debug(void)
{
    mini_printf("\e[33mDEBUG\n\e[0m");
}

int main(void)
{
    game_t game;

    srand(time(NULL));
    init(&game);
    print_map(&game);
    start_screen(&game);
    destroy(&game);
    return 0;
}
