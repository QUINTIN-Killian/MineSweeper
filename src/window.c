#include "../include/minesweeper.h"

void init_window(minesweeper_t *minesweeper)
{
    minesweeper->window = malloc(sizeof(window_t));
    __videoMode__ = (sfVideoMode){800, 600, 64};
    __renderWindow__ = sfRenderWindow_create(__videoMode__,
    "MineSweeper (created by Killian QUINTIN)", sfClose, NULL);
    __windowSize__ = sfRenderWindow_getSize(__renderWindow__);
    sfRenderWindow_setFramerateLimit(__renderWindow__, 64);
    __mainFont__ =
    sfFont_createFromFile("fonts/CartoonComicItalic-mLLAx.ttf");
    minesweeper->window->background =
    mySfSprite_create("backgrounds/MineSweeperBackground.png", sfTrue);
    sfSprite_setPosition(minesweeper->window->background->sprite, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 2});
    __windowInfos__ = (renderWindowObj){__renderWindow__, __videoMode__};
}

void draw_background(minesweeper_t *minesweeper)
{
    sfRenderWindow_drawSprite(__renderWindow__,
    minesweeper->window->background->sprite, NULL);
}

void dig_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(minesweeper->sounds->mining_sound->sound);
    }
}

void close_window_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtClosed ||
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(__renderWindow__);
    }
}

void destroy_window(minesweeper_t *minesweeper)
{
    sfFont_destroy(__mainFont__);
    mySfSprite_destroy(minesweeper->window->background);
    sfRenderWindow_destroy(__renderWindow__);
    free(minesweeper->window);
}
