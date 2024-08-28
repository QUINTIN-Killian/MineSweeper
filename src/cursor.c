#include "../include/minesweeper.h"

void init_cursor(minesweeper_t *minesweeper)
{
    minesweeper->cursor = malloc(sizeof(cursor_t));
    minesweeper->cursor->state = DEFAULT;
    minesweeper->cursor->cursor = mySfSpriteCreate("images/pickaxe.png", sfTrue);
    sfSprite_setScale(minesweeper->cursor->cursor->sprite, (sfVector2f){0.08, 0.08});
}

void draw_cursor(minesweeper_t *minesweeper)
{
    sfVector2i mouse_pos;
    sfVector2f sprite_pos;

    if (minesweeper->cursor->state == DEFAULT)
        return;
    mouse_pos = sfMouse_getPositionRenderWindow(__renderWindow__);
    sprite_pos = sfRenderWindow_mapPixelToCoords(__renderWindow__,
    mouse_pos, NULL);
    sprite_pos.x += sfTexture_getSize(minesweeper->cursor->cursor->texture).x /
    2.5 * sfSprite_getScale(minesweeper->cursor->cursor->sprite).x;
    sprite_pos.y -= sfTexture_getSize(minesweeper->cursor->cursor->texture).y /
    6 * sfSprite_getScale(minesweeper->cursor->cursor->sprite).y;
    sfSprite_setPosition(minesweeper->cursor->cursor->sprite, sprite_pos);
    sfRenderWindow_drawSprite(__renderWindow__,
    minesweeper->cursor->cursor->sprite, NULL);
}

void destroy_cursor(minesweeper_t *minesweeper)
{
    mySfSpriteDestroy(minesweeper->cursor->cursor);
    free(minesweeper->cursor);
}
