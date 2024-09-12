#include "../include/minesweeper.h"

void init_start(minesweeper_t *minesweeper)
{
    char *str;

    if (minesweeper->start != NULL)
        return;
    minesweeper->start = malloc(sizeof(start_t));
    minesweeper->start->minesweeper_name = mySfText_create(__mainFont__,
    "MineSweeper", sfWhite, H3);
    sfText_setPosition(minesweeper->start->minesweeper_name, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 4});
    minesweeper->start->start = mySfText_create(__mainFont__,
    "Start", sfWhite, H7);
    mySfText_setOrigin(minesweeper->start->start, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->start, (sfVector2f)
    {__windowSize__.x / 20, __windowSize__.y / 2});
    minesweeper->start->leave = mySfText_create(__mainFont__,
    "Leave", sfWhite, H7);
    mySfText_setOrigin(minesweeper->start->leave, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->leave, (sfVector2f)
    {__windowSize__.x / 20, __windowSize__.y / 1.5});
    str = concat_str(2, "Difficulty: ", get_difficulty(minesweeper));
    minesweeper->start->change_difficulty = mySfText_create(__mainFont__,
    str, sfWhite, H9);
    free(str);
    mySfText_setOrigin(minesweeper->start->change_difficulty, BOTTOM_RIGHT);
    sfText_setPosition(minesweeper->start->change_difficulty, (sfVector2f)
    {__windowSize__.x, __windowSize__.y});
}

void destroy_start(minesweeper_t *minesweeper)
{
    if (minesweeper->start == NULL)
        return;
    mySfText_destroy(minesweeper->start->minesweeper_name);
    mySfText_destroy(minesweeper->start->start);
    mySfText_destroy(minesweeper->start->leave);
    mySfText_destroy(minesweeper->start->change_difficulty);
    free(minesweeper->start);
    minesweeper->start = NULL;
}
