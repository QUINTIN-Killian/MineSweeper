#include "../include/minesweeper.h"

void init_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->window_name = "MineSweeper (created by Killian QUINTIN)";
    game->window->mode = (sfVideoMode){800, 600, 64};
    game->window->infos = sfRenderWindow_create(game->window->mode,
    game->window->window_name, sfResize | sfClose, NULL);
    game->window->window_size = sfRenderWindow_getSize(game->window->infos);
    sfRenderWindow_setFramerateLimit(game->window->infos, 60);
    game->window->main_font =
    sfFont_createFromFile("fonts/CartoonComicItalic-mLLAx.ttf");
    game->window->background =
    mySfSpriteCreate("backgrounds/background5.png", sfTrue);
    sfSprite_setPosition(game->window->background->sprite, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
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
