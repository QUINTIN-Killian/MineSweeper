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
    init_sounds(game);
    init_musics(game);
}

static void destroy(game_t *game)
{
    destroy_sounds(game);
    destroy_cursor(game);
    destroy_window(game);
    destroy_map(game);
    destroy_musics(game);
}

void debug(void)
{
    mini_printf("\e[33mDEBUG\n\e[0m");
}

static int help(void)
{
    mini_printf("Welcome in MineSweeper !\n\n");
    mini_printf("Your goal is to reveal the content of all the rocks ");
    mini_printf("underground except the ones containing bombs which must be ");
    mini_printf("flaged.\n");
    mini_printf("The number found in a rock indicates the number of ");
    mini_printf("adjacent bombs.\n");
    mini_printf("\t- Press MOUSE LEFT to dig a rock\n");
    mini_printf("\t- Press MOUSE RIGHT to flag a rock\n");
    mini_printf("\t- Press H to show help\n");
    mini_printf("\t- Press SPACE BAR to turn off/on the musics\n");
    mini_printf("\t- Press UP/DOWN to manage the musics volume\n");
    mini_printf("\n(Game created by Killian QUINTIN)\n");
    return 0;
}

int main(int ac, char **av)
{
    game_t game;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return help();
    srand(time(NULL));
    init(&game);
    print_map(&game);
    credits(&game);
    destroy(&game);
    return 0;
}
