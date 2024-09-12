#include "../include/minesweeper.h"

static void set_game_info(minesweeper_t *minesweeper, int x, int y,
    int nb_bombs)
{
    minesweeper->width = x;
    minesweeper->height = y;
    minesweeper->total_box = minesweeper->width * minesweeper->height;
    minesweeper->box_left = minesweeper->total_box;
    minesweeper->total_bombs = nb_bombs;
    minesweeper->bombs_left = minesweeper->total_bombs;
}

void set_difficulty(minesweeper_t *minesweeper)
{
    switch (minesweeper->difficulty) {
    case EASY:
        return set_game_info(minesweeper, 10, 8, 7);
    case NORMAL:
        return set_game_info(minesweeper, 14, 9, 15);
    case HARD:
        return set_game_info(minesweeper, 20, 15, 40);
    case EXPERT:
        return set_game_info(minesweeper, 26, 19, 99);
    default:
        mini_fdprintf(2, "Unknown difficulty.\n");
        return set_game_info(minesweeper, 14, 9, 15);
    }
}

char *get_difficulty(minesweeper_t *minesweeper)
{
    switch (minesweeper->difficulty) {
    case EASY:
        return "Easy";
    case NORMAL:
        return "Normal";
    case HARD:
        return "Hard";
    case EXPERT:
        return "Expert";
    default:
        return "Error";
    }
}

void change_difficulty(minesweeper_t *minesweeper)
{
    char *str;

    minesweeper->difficulty++;
    if (minesweeper->difficulty > EXPERT)
        minesweeper->difficulty = EASY;
    str = concat_str(2, "Difficulty: ", get_difficulty(minesweeper));
    sfText_setString(minesweeper->start->change_difficulty, str);
    mySfText_setOrigin(minesweeper->start->change_difficulty, BOTTOM_RIGHT);
    sfText_setPosition(minesweeper->start->change_difficulty, (sfVector2f)
    {__windowSize__.x, __windowSize__.y});
    free(str);
}
