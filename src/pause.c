#include "../include/minesweeper.h"

static void init_pause_text(minesweeper_t *minesweeper, sfVector2f size)
{
    minesweeper->pause->pause = mySfText_create(__mainFont__, "PAUSE",
    sfWhite, VERY_BIG);
    sfText_setPosition(minesweeper->pause->pause,
    (sfVector2f){__windowSize__.x / 2, size.y / 4});
    minesweeper->pause->resume = mySfText_create(__mainFont__, "RESUME",
    sfWhite, MEDIUM);
    sfText_setPosition(minesweeper->pause->resume,
    (sfVector2f){__windowSize__.x / 2, size.y / 2});
    minesweeper->pause->restart = mySfText_create(__mainFont__, "RESTART",
    sfWhite, MEDIUM);
    sfText_setPosition(minesweeper->pause->restart,
    (sfVector2f){__windowSize__.x / 2, size.y / 1.5});
    minesweeper->pause->leave = mySfText_create(__mainFont__, "LEAVE",
    sfWhite, MEDIUM);
    sfText_setPosition(minesweeper->pause->leave,
    (sfVector2f){__windowSize__.x / 2, size.y / 1.2});
}

void init_pause(minesweeper_t *minesweeper)
{
    sfVector2f size;

    minesweeper->pause = malloc(sizeof(pause_t));
    minesweeper->pause->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(minesweeper->pause->background,
    (sfColor){170, 170, 170, 230});
    sfRectangleShape_setOutlineThickness(minesweeper->pause->background, 3.0);
    sfRectangleShape_setOutlineColor(minesweeper->pause->background, sfBlack);
    size = (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 1.1};
    sfRectangleShape_setSize(minesweeper->pause->background, size);
    sfRectangleShape_setOrigin(minesweeper->pause->background,
    (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(minesweeper->pause->background,
    (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 2});
    init_pause_text(minesweeper, size);
}

void destroy_pause(minesweeper_t *minesweeper)
{
    mySfText_destroy(minesweeper->pause->pause);
    mySfText_destroy(minesweeper->pause->resume);
    mySfText_destroy(minesweeper->pause->restart);
    mySfText_destroy(minesweeper->pause->leave);
    sfRectangleShape_destroy(minesweeper->pause->background);
    free(minesweeper->pause);
}
