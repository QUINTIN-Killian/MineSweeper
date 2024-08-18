#include "../include/minesweeper.h"

void dig_animation(game_t *game)
{
    if (game->cursor->state == END &&
    sfSprite_getRotation(game->cursor->cursor_sprite) == 0.0) {
        game->cursor->state = DEFAULT;
        return;
    }
    if (game->cursor->state == DIG &&
    sfSprite_getRotation(game->cursor->cursor_sprite) == 300.0)
        game->cursor->state = END;
    if (game->cursor->state == END) {
        sfSprite_setRotation(game->cursor->cursor_sprite,
        sfSprite_getRotation(game->cursor->cursor_sprite) + 5.0);
        return;
    }
    if (game->cursor->state == DIG)
        sfSprite_setRotation(game->cursor->cursor_sprite,
        sfSprite_getRotation(game->cursor->cursor_sprite) - 5.0);
}
