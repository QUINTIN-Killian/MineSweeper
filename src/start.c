#include "../include/minesweeper.h"

void init_start(minesweeper_t *minesweeper)
{
    minesweeper->start = malloc(sizeof(start_t));
    minesweeper->start->minesweeper_name = mySfText_create(__mainFont__,
    "MineSweeper", sfWhite, VERY_BIG);
    sfText_setPosition(minesweeper->start->minesweeper_name, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 4});
    minesweeper->start->start = mySfText_create(__mainFont__,
    "Start", sfWhite, MEDIUM);
    mySfText_setOrigin(minesweeper->start->start, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->start, (sfVector2f)
    {__windowSize__.x / 20, __windowSize__.y / 2});
    minesweeper->start->leave = mySfText_create(__mainFont__,
    "Leave", sfWhite, MEDIUM);
    mySfText_setOrigin(minesweeper->start->leave, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->leave, (sfVector2f)
    {__windowSize__.x / 20, __windowSize__.y / 1.5});
    minesweeper->start->start_minesweeper = false;
}

void destroy_start(minesweeper_t *minesweeper)
{
    mySfText_destroy(minesweeper->start->minesweeper_name);
    mySfText_destroy(minesweeper->start->start);
    mySfText_destroy(minesweeper->start->leave);
    free(minesweeper->start);
}
