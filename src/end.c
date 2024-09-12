#include "../include/minesweeper.h"

static void init_end_text(minesweeper_t *minesweeper, sfVector2f size)
{
    if (minesweeper->screen == VICTORY)
        minesweeper->end->state = mySfText_create(__mainFont__, "VICTORY",
        sfWhite, H4);
    else
        minesweeper->end->state = mySfText_create(__mainFont__, "DEFEAT",
        sfWhite, H4);
    sfText_setPosition(minesweeper->end->state,
    (sfVector2f){__windowSize__.x / 2, size.y / 4});
    minesweeper->end->restart = mySfText_create(__mainFont__, "RESTART",
    sfWhite, H7);
    sfText_setPosition(minesweeper->end->restart,
    (sfVector2f){__windowSize__.x / 2, size.y / 2});
    minesweeper->end->main_menu = mySfText_create(__mainFont__, "MAIN MENU",
    sfWhite, H7);
    sfText_setPosition(minesweeper->end->main_menu,
    (sfVector2f){__windowSize__.x / 2, size.y / 1.5});
}

void init_end(minesweeper_t *minesweeper)
{
    sfVector2f size;

    if (minesweeper->end != NULL)
        return;
    minesweeper->end = malloc(sizeof(end_t));
    minesweeper->end->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(minesweeper->end->background,
    (sfColor){170, 170, 170, 230});
    sfRectangleShape_setOutlineThickness(minesweeper->end->background, 3.0);
    sfRectangleShape_setOutlineColor(minesweeper->end->background, sfBlack);
    size = (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 1.1};
    sfRectangleShape_setSize(minesweeper->end->background, size);
    sfRectangleShape_setOrigin(minesweeper->end->background,
    (sfVector2f){size.x / 2, size.y / 2});
    sfRectangleShape_setPosition(minesweeper->end->background,
    (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 2});
}

void destroy_end(minesweeper_t *minesweeper)
{
    if (minesweeper->end == NULL)
        return;
    sfRectangleShape_destroy(minesweeper->end->background);
    sfText_destroy(minesweeper->end->state);
    sfText_destroy(minesweeper->end->restart);
    sfText_destroy(minesweeper->end->main_menu);
    free(minesweeper->end);
    minesweeper->end = NULL;
}
