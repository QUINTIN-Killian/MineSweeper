#include "../include/minesweeper.h"

void init_window(game_t *game)
{
    game->window = malloc(sizeof(window_t));
    game->window->window_name = "MineSweeper (created by Killian QUINTIN)";
    game->window->mode = (sfVideoMode){800, 600, 64};
    __renderWindow__ = sfRenderWindow_create(game->window->mode,
    game->window->window_name, sfResize | sfClose, NULL);
    __windowSize__ = sfRenderWindow_getSize(__renderWindow__);
    sfRenderWindow_setFramerateLimit(__renderWindow__, 60);
    game->window->main_font =
    sfFont_createFromFile("fonts/CartoonComicItalic-mLLAx.ttf");
    game->window->background =
    mySfSpriteCreate("backgrounds/background5.png", sfTrue);
    sfSprite_setPosition(game->window->background->sprite, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 2});
}

void draw_background(game_t *game)
{
    sfRenderWindow_drawSprite(__renderWindow__,
    game->window->background->sprite, NULL);
}

void destroy_window(game_t *game)
{
    sfFont_destroy(game->window->main_font);
    mySfSpriteDestroy(game->window->background);
    sfRenderWindow_destroy(__renderWindow__);
    free(game->window);
}
