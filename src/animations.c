#include "../include/minesweeper.h"

void dig_animation(minesweeper_t *minesweeper)
{
    if (minesweeper->cursor->state == END &&
    sfSprite_getRotation(minesweeper->cursor->cursor->sprite) == 0.0) {
        minesweeper->cursor->state = DEFAULT;
        sfRenderWindow_setMouseCursorVisible(__renderWindow__, sfTrue);
        return;
    }
    if (minesweeper->cursor->state == DIG &&
    sfSprite_getRotation(minesweeper->cursor->cursor->sprite) == 300.0)
        minesweeper->cursor->state = END;
    if (minesweeper->cursor->state == END) {
        sfSprite_setRotation(minesweeper->cursor->cursor->sprite,
        sfSprite_getRotation(minesweeper->cursor->cursor->sprite) + 5.0);
        return;
    }
    if (minesweeper->cursor->state == DIG)
        sfSprite_setRotation(minesweeper->cursor->cursor->sprite,
        sfSprite_getRotation(minesweeper->cursor->cursor->sprite) - 5.0);
}
