#include "../include/minesweeper.h"

void init_credits(minesweeper_t *minesweeper)
{
    if (minesweeper->credits != NULL)
        return;
    minesweeper->credits = malloc(sizeof(credits_t));
    minesweeper->credits->show = true;
    minesweeper->credits->credits_text = mySfText_create(__mainFont__,
    "Game created by Killian QUINTIN", (sfColor){255, 255, 255, 0}, NONE);
    sfText_setPosition(minesweeper->credits->credits_text, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 2});
}

void destroy_credits(minesweeper_t *minesweeper)
{
    if (minesweeper->credits == NULL)
        return;
    mySfText_destroy(minesweeper->credits->credits_text);
    free(minesweeper->credits);
    minesweeper->credits = NULL;
}
