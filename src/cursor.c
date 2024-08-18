#include "../include/minesweeper.h"

void init_cursor(game_t *game)
{
    game->cursor = malloc(sizeof(cursor_t));
    game->cursor->pickaxe_cursor = true;
    game->cursor->state = DEFAULT;
    sfRenderWindow_setMouseCursorVisible(game->window->infos, sfFalse);
    game->cursor->cursor_sprite = sfSprite_create();
    game->cursor->cursor_texture =
    sfTexture_createFromFile("images/pickaxe.png", NULL);
    sfSprite_setTexture(game->cursor->cursor_sprite,
    game->cursor->cursor_texture, sfFalse);
    sfSprite_setScale(game->cursor->cursor_sprite, (sfVector2f){0.08, 0.08});
    sfSprite_setOrigin(game->cursor->cursor_sprite,
    (sfVector2f){sfTexture_getSize(game->cursor->cursor_texture).x / 2,
    sfTexture_getSize(game->cursor->cursor_texture).y / 2});
}

void draw_cursor(game_t *game)
{
    sfVector2i mouse_pos;
    sfVector2f sprite_pos;

    if (game->cursor->pickaxe_cursor) {
        mouse_pos = sfMouse_getPositionRenderWindow(game->window->infos);
        sprite_pos = sfRenderWindow_mapPixelToCoords(game->window->infos,
        mouse_pos, NULL);
        sprite_pos.x += sfTexture_getSize(game->cursor->cursor_texture).x /
        2.5 * sfSprite_getScale(game->cursor->cursor_sprite).x;
        sprite_pos.y -= sfTexture_getSize(game->cursor->cursor_texture).y /
        6 * sfSprite_getScale(game->cursor->cursor_sprite).y;
        sfSprite_setPosition(game->cursor->cursor_sprite, sprite_pos);
        sfRenderWindow_drawSprite(game->window->infos,
        game->cursor->cursor_sprite, NULL);
    }
}

void destroy_cursor(game_t *game)
{
    sfSprite_destroy(game->cursor->cursor_sprite);
    sfTexture_destroy(game->cursor->cursor_texture);
    free(game->cursor);
}
