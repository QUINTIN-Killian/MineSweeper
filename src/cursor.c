#include "../include/minesweeper.h"

void init_cursor(minesweeper_t *minesweeper)
{
    minesweeper->cursor = malloc(sizeof(cursor_t));
    minesweeper->cursor->state = DEFAULT;
    minesweeper->cursor->cursor = mySfSpriteCreate("images/pickaxe.png", sfTrue);
    sfSprite_setScale(minesweeper->cursor->cursor->sprite, (sfVector2f){0.08, 0.08});
}

void destroy_cursor(minesweeper_t *minesweeper)
{
    mySfSpriteDestroy(minesweeper->cursor->cursor);
    free(minesweeper->cursor);
}
