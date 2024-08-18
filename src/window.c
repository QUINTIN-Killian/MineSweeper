#include "../include/minesweeper.h"

void init_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->desktop_mode = sfVideoMode_getDesktopMode();
    game->window->window_name = "MineSweeper (created by Killian QUINTIN)";
    game->window->infos = sfRenderWindow_create(game->window->desktop_mode,
    game->window->window_name, sfResize | sfClose, NULL);
    game->window->window_size = sfRenderWindow_getSize(game->window->infos);
    sfRenderWindow_setFramerateLimit(game->window->infos, 60);
    game->window->main_font =
    sfFont_createFromFile("font/BlackerShield-V4VRZ.ttf");
    game->window->background_sprite = sfSprite_create();
    game->window->background_texture =
    sfTexture_createFromFile("backgrounds/cartoon_soil_891x480.png", NULL);
    sfSprite_setTexture(game->window->background_sprite,
    game->window->background_texture, sfFalse);
    game->window->background_size =
    sfTexture_getSize(game->window->background_texture);
    sfSprite_setScale(game->window->background_sprite,
    (sfVector2f){(float)game->window->desktop_mode.width /
    game->window->background_size.x, (float)game->window->desktop_mode.height /
    game->window->background_size.y});
}

void draw_background(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->infos,
    game->window->background_sprite, NULL);
}

void destroy_window(game_t *game)
{
    sfFont_destroy(game->window->main_font);
    sfSprite_destroy(game->window->background_sprite);
    sfTexture_destroy(game->window->background_texture);
    sfRenderWindow_destroy(game->window->infos);
    free(game->window);
}
