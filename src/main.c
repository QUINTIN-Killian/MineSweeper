#include "../include/minesweeper.h"

static void init(minesweeper_t *minesweeper)
{
    minesweeper->screen = START; //remettre CREDITS
    minesweeper->difficulty = NORMAL;
    set_difficulty(minesweeper);
    create_map(minesweeper);
    init_window(minesweeper);
    init_sounds(minesweeper);
    init_musics(minesweeper);
    minesweeper->credits = NULL;
    minesweeper->start = NULL;
    minesweeper->game = NULL;
    minesweeper->pause = NULL;
}

static void destroy(minesweeper_t *minesweeper)
{
    destroy_sounds(minesweeper);
    destroy_window(minesweeper);
    destroy_map(minesweeper);
    destroy_musics(minesweeper);
    destroy_start(minesweeper);
    destroy_game(minesweeper);
    destroy_pause(minesweeper);
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
    mini_printf("\t- Press SPACE BAR to turn off/on the musics\n");
    mini_printf("\t- Press UP/DOWN to manage the musics volume\n");
    mini_printf("\n(minesweeper created by Killian QUINTIN)\n");
    return 0;
}

int main(int ac, char **av)
{
    minesweeper_t minesweeper;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return help();
    srand(time(NULL));
    init(&minesweeper);
    screen_manager(&minesweeper);
    destroy(&minesweeper);
    return 0;
}
