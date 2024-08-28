#include "../include/minesweeper.h"

void init_cursor(game_t *game)
{
    game->cursor = malloc(sizeof(cursor_t));
    game->cursor->pickaxe_cursor = true;
    game->cursor->state = DEFAULT;
    sfRenderWindow_setMouseCursorVisible(__renderWindow__, sfFalse);
    game->cursor->cursor = mySfSpriteCreate("images/pickaxe.png", sfTrue);
    sfSprite_setScale(game->cursor->cursor->sprite, (sfVector2f){0.08, 0.08});
}

void draw_cursor(game_t *game)
{
    sfVector2i mouse_pos;
    sfVector2f sprite_pos;

    if (game->cursor->pickaxe_cursor) {
        mouse_pos = sfMouse_getPositionRenderWindow(__renderWindow__);
        sprite_pos = sfRenderWindow_mapPixelToCoords(__renderWindow__,
        mouse_pos, NULL);
        sprite_pos.x += sfTexture_getSize(game->cursor->cursor->texture).x /
        2.5 * sfSprite_getScale(game->cursor->cursor->sprite).x;
        sprite_pos.y -= sfTexture_getSize(game->cursor->cursor->texture).y /
        6 * sfSprite_getScale(game->cursor->cursor->sprite).y;
        sfSprite_setPosition(game->cursor->cursor->sprite, sprite_pos);
        sfRenderWindow_drawSprite(__renderWindow__,
        game->cursor->cursor->sprite, NULL);
    }
}

void destroy_cursor(game_t *game)
{
    mySfSpriteDestroy(game->cursor->cursor);
    free(game->cursor);
}
