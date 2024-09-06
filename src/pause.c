#include "../include/minesweeper.h"

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
}

void destroy_pause(minesweeper_t *minesweeper)
{
    sfRectangleShape_destroy(minesweeper->pause->background);
    free(minesweeper->pause);
}
