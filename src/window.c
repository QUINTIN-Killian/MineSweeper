#include "../include/minesweeper.h"

void init_window(game_t *game)
{
    sfVector2u background_size;

    game->window = malloc(sizeof(window_t));
    game->window->desktop_mode = sfVideoMode_getDesktopMode();
    game->window->window_name = "MineSweeper (created by Killian QUINTIN)";
    game->window->infos = sfRenderWindow_create(game->window->desktop_mode,
    game->window->window_name, sfResize | sfClose, NULL);
    game->window->window_size = sfRenderWindow_getSize(game->window->infos);
    sfRenderWindow_setFramerateLimit(game->window->infos, 60);
    game->window->main_font =
    sfFont_createFromFile("fonts/CartoonComicItalic-mLLAx.ttf");
    game->window->background =
    mySfSpriteCreate("backgrounds/cartoon_soil_891x480.png");
    background_size = sfTexture_getSize(game->window->background->texture);
    sfSprite_setScale(game->window->background->sprite, (sfVector2f){
    (float)game->window->desktop_mode.width / background_size.x,
    (float)game->window->desktop_mode.height / background_size.y});
    sfSprite_setPosition(game->window->background->sprite, (sfVector2f)
    {game->window->desktop_mode.width / 2,
    game->window->desktop_mode.height / 2});
}

void draw_background(game_t *game)
{
    sfRenderWindow_drawSprite(game->window->infos,
    game->window->background->sprite, NULL);
}

void destroy_window(game_t *game)
{
    sfFont_destroy(game->window->main_font);
    mySfSpriteDestroy(game->window->background);
    sfRenderWindow_destroy(game->window->infos);
    free(game->window);
}
