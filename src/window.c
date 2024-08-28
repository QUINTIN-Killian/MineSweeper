#include "../include/minesweeper.h"

void init_window(minesweeper_t *minesweeper)
{
    minesweeper->window = malloc(sizeof(window_t));
    minesweeper->window->mode = (sfVideoMode){800, 600, 64};
    __renderWindow__ = sfRenderWindow_create(minesweeper->window->mode,
    "MineSweeper (created by Killian QUINTIN)", sfResize | sfClose, NULL);
    __windowSize__ = sfRenderWindow_getSize(__renderWindow__);
    sfRenderWindow_setFramerateLimit(__renderWindow__, 60);
    minesweeper->window->main_font =
    sfFont_createFromFile("fonts/CartoonComicItalic-mLLAx.ttf");
    minesweeper->window->background =
    mySfSpriteCreate("backgrounds/background5.png", sfTrue);
    sfSprite_setPosition(minesweeper->window->background->sprite, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 2});
}

void destroy_window(minesweeper_t *minesweeper)
{
    sfFont_destroy(minesweeper->window->main_font);
    mySfSpriteDestroy(minesweeper->window->background);
    sfRenderWindow_destroy(__renderWindow__);
    free(minesweeper->window);
}
