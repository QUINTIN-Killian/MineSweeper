#include "../include/minesweeper.h"

void init_start(minesweeper_t *minesweeper)
{
    minesweeper->start = malloc(sizeof(start_t));
    minesweeper->start->minesweeper_name = mySfTextCreate(minesweeper->window->main_font,
    "MineSweeper", sfWhite, VERY_BIG);
    sfText_setPosition(minesweeper->start->minesweeper_name, (sfVector2f)
    {__windowSize__.x / 2, minesweeper->window->window_size.y / 4});
    minesweeper->start->start = mySfTextCreate(minesweeper->window->main_font,
    "Start", sfWhite, MEDIUM);
    mySfTextSetOrigin(minesweeper->start->start, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->start, (sfVector2f)
    {__windowSize__.x / 20, minesweeper->window->window_size.y / 2});
    minesweeper->start->leave = mySfTextCreate(minesweeper->window->main_font,
    "Leave", sfWhite, MEDIUM);
    mySfTextSetOrigin(minesweeper->start->leave, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->leave, (sfVector2f)
    {__windowSize__.x / 20, minesweeper->window->window_size.y / 1.5});
    minesweeper->start->start_minesweeper = false;
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

void destroy_start(minesweeper_t *minesweeper)
{
    mySfTextDestroy(minesweeper->start->minesweeper_name);
    mySfTextDestroy(minesweeper->start->start);
    mySfTextDestroy(minesweeper->start->leave);
    free(minesweeper->start);
}

static void start__normal(sfText *start)
{
    sfText_setFillColor(start, sfWhite);
    sfText_setCharacterSize(start, MEDIUM);
}

static void start__hoover(sfText *start)
{
    sfText_setFillColor(start, (sfColor){170, 170, 170, 255});
    sfText_setCharacterSize(start, 50);
}

static void start__click(sfText *start)
{
    sfText_setFillColor(start, (sfColor){110, 110, 110, 255});
    sfText_setCharacterSize(start, 45);
}

void start_event(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, minesweeper->window->mode};

    mySfButtonTextNormal(&obj, minesweeper->start->start, &start__normal);
    mySfButtonTextHoover(&obj, minesweeper->start->start, &start__hoover);
    if (mySfButtonTextClick(&obj, minesweeper->start->start, event,
    &start__click)) {
        sfSound_play(minesweeper->sounds->breaking_sound->sound);
        minesweeper->start->start_minesweeper = true;
    }
}

static void leave__normal(sfText *leave)
{
    sfText_setFillColor(leave, sfWhite);
    sfText_setCharacterSize(leave, MEDIUM);
}

static void leave__hoover(sfText *leave)
{
    sfText_setFillColor(leave, (sfColor){128, 128, 128, 255});
    sfText_setCharacterSize(leave, 50);
}

static void leave__click(sfText *leave)
{
    sfText_setFillColor(leave, (sfColor){170, 170, 170, 255});
    sfText_setCharacterSize(leave, 45);
}

void leave_screen_event(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, minesweeper->window->mode};

    mySfButtonTextNormal(&obj, minesweeper->start->leave, &leave__normal);
    mySfButtonTextHoover(&obj, minesweeper->start->leave, &leave__hoover);
    if (mySfButtonTextClick(&obj, minesweeper->start->leave, event,
    &leave__click)) {
        sfSound_play(minesweeper->sounds->breaking_sound->sound);
        sfRenderWindow_close(__renderWindow__);
    }
}

void start(minesweeper_t *minesweeper)
{
    init_start(minesweeper);
    while (sfRenderWindow_isOpen(__renderWindow__) &&
    !minesweeper->start->start_minesweeper) {
        sfRenderWindow_clear(__renderWindow__, sfCyan);
        draw_background(minesweeper);
        draw_start(minesweeper);
        draw_cursor(minesweeper);
        get_event(minesweeper, 6, &close_window_event,
        &dig_animation_event, &mute_musics_event, &manage_musics_event,
        &start_event, &leave_screen_event);
        dig_animation(minesweeper);
        sfRenderWindow_display(__renderWindow__);
    }
    destroy_start(minesweeper);
}
