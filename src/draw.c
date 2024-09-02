#include "../include/minesweeper.h"

void draw_background(minesweeper_t *minesweeper)
{
    sfRenderWindow_drawSprite(__renderWindow__,
    minesweeper->window->background->sprite, NULL);
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
