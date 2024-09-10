#include "../include/minesweeper.h"

static void init(minesweeper_t *minesweeper)
{
    minesweeper->screen = BLANK;
    minesweeper->width = 26; //default : 19, ici : 26
    minesweeper->height = 19; //default : 26, ici : 19
    minesweeper->total_box = minesweeper->width * minesweeper->height;
    minesweeper->total_bombs = 99;
    minesweeper->bombs_left = minesweeper->total_bombs;
    create_map(minesweeper);
    init_window(minesweeper);
    init_sounds(minesweeper);
    init_musics(minesweeper);
}

static void destroy(minesweeper_t *minesweeper)
{
    destroy_sounds(minesweeper);
    destroy_window(minesweeper);
    destroy_map(minesweeper);
    destroy_musics(minesweeper);
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
    //credits(&minesweeper);
    start(&minesweeper);
    destroy(&minesweeper);
    return 0;
}
