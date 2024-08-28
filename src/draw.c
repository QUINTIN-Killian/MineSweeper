#include "../include/minesweeper.h"

void draw_background(minesweeper_t *minesweeper)
{
    sfRenderWindow_drawSprite(__renderWindow__,
    minesweeper->window->background->sprite, NULL);
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

void draw_start(minesweeper_t *minesweeper)
{
    sfRenderWindow_drawText(__renderWindow__,
    minesweeper->start->minesweeper_name, NULL);
    sfRenderWindow_drawText(__renderWindow__,
    minesweeper->start->start, NULL);
    sfRenderWindow_drawText(__renderWindow__,
    minesweeper->start->leave, NULL);
}

void draw(minesweeper_t *minesweeper, int nb_draw, ...)
{
    va_list args;
    void (*draw_func)(minesweeper_t *) = NULL;

    va_start(args, nb_draw);
    for (int i = 0; i < nb_draw; i++) {
        draw_func = va_arg(args, void (*)(minesweeper_t *));
        if (draw_func)
            draw_func(minesweeper);
    }
    va_end(args);
}
