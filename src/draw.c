#include "../include/minesweeper.h"

void draw_pause(minesweeper_t *minesweeper)
{
    sfRenderWindow_drawRectangleShape(__renderWindow__,
    minesweeper->pause->background, NULL);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->pause->pause,
    NULL);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->pause->resume,
    NULL);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->pause->restart,
    NULL);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->pause->main_menu,
    NULL);
}

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

void draw_game(minesweeper_t *minesweeper)
{
    char *bombs_left = convert_int_to_str(minesweeper->bombs_left);
    char *str = concat_str(2, ": ", bombs_left);

    sfRenderWindow_drawSprite(__renderWindow__,
    minesweeper->game->bomb->sprite, NULL);
    sfText_setString(minesweeper->game->bombs_left, str);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->game->bombs_left,
    NULL);
    free(bombs_left);
    free(str);
}

void draw_timer(minesweeper_t *minesweeper)
{
    sfTime time = mySfClock_getElapsedTime(minesweeper->game->clock);
    float seconds = sfTime_asSeconds(time);
    char *tmp = convert_int_to_str(seconds);

    sfText_setString(minesweeper->game->timer, tmp);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->game->timer, NULL);
    free(tmp);
}

void draw_grid(minesweeper_t *minesweeper)
{
    for (int i = 0; i < minesweeper->height; i++)
        for (int j = 0; j < minesweeper->width; j++)
            draw_box(minesweeper, &minesweeper->game->grid[i][j]);
}

void draw_box(minesweeper_t *minesweeper, box_t *box)
{
    sfRenderWindow_drawRectangleShape(__renderWindow__, box->rectangle, NULL);
    if (box->state == REVEALED) {
        if (box->textValue != NULL)
            sfRenderWindow_drawText(__renderWindow__, box->textValue, NULL);
        if (box->mine != NULL)
            sfRenderWindow_drawSprite(__renderWindow__, box->mine->sprite,
            NULL);
        return;
    }
    if (box->state == FLAGED) {
        sfRenderWindow_drawSprite(__renderWindow__, box->flag->sprite,
        NULL);
        return;
    }
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
