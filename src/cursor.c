#include "../include/minesweeper.h"

void init_cursor(minesweeper_t *minesweeper)
{
    minesweeper->cursor = malloc(sizeof(cursor_t));
    minesweeper->cursor->state = DEFAULT;
    minesweeper->cursor->cursor = mySfSprite_create("images/Pickaxe.png", sfTrue);
    sfSprite_setScale(minesweeper->cursor->cursor->sprite, (sfVector2f){0.08, 0.08});
}

void destroy_cursor(minesweeper_t *minesweeper)
{
    mySfSprite_destroy(minesweeper->cursor->cursor);
    free(minesweeper->cursor);
}
