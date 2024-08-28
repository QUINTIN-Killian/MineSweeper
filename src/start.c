#include "../include/minesweeper.h"

void init_start(minesweeper_t *minesweeper)
{
    minesweeper->start = malloc(sizeof(start_t));
    minesweeper->start->minesweeper_name = mySfText_create(minesweeper->window->main_font,
    "MineSweeper", sfWhite, VERY_BIG);
    sfText_setPosition(minesweeper->start->minesweeper_name, (sfVector2f)
    {__windowSize__.x / 2, minesweeper->window->window_size.y / 4});
    minesweeper->start->start = mySfText_create(minesweeper->window->main_font,
    "Start", sfWhite, MEDIUM);
    mySfText_setOrigin(minesweeper->start->start, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->start, (sfVector2f)
    {__windowSize__.x / 20, minesweeper->window->window_size.y / 2});
    minesweeper->start->leave = mySfText_create(minesweeper->window->main_font,
    "Leave", sfWhite, MEDIUM);
    mySfText_setOrigin(minesweeper->start->leave, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->leave, (sfVector2f)
    {__windowSize__.x / 20, minesweeper->window->window_size.y / 1.5});
    minesweeper->start->start_minesweeper = false;
}

void destroy_start(minesweeper_t *minesweeper)
{
    mySfText_destroy(minesweeper->start->minesweeper_name);
    mySfText_destroy(minesweeper->start->start);
    mySfText_destroy(minesweeper->start->leave);
    free(minesweeper->start);
}

static void start__normal(sfText *start)
{
    sfText_setFillColor(start, sfWhite);
    sfText_setCharacterSize(start, MEDIUM);
}

static void start__hoover(sfText *start)
{
    sfText_setFillColor(start, sfGrey);
    sfText_setCharacterSize(start, 50);
}

static void start__click(sfText *start)
{
    sfText_setFillColor(start, sfDarkGrey);
    sfText_setCharacterSize(start, 45);
}

void start_startEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, minesweeper->window->mode};

    mySfButtonText_normal(&obj, minesweeper->start->start, &start__normal);
    mySfButtonText_hoover(&obj, minesweeper->start->start, &start__hoover);
    if (mySfButtonText_click(&obj, minesweeper->start->start, event,
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
    sfText_setFillColor(leave, sfGrey);
    sfText_setCharacterSize(leave, 50);
}

static void leave__click(sfText *leave)
{
    sfText_setFillColor(leave, sfDarkGrey);
    sfText_setCharacterSize(leave, 45);
}

void start_leaveEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, minesweeper->window->mode};

    mySfButtonText_normal(&obj, minesweeper->start->leave, &leave__normal);
    mySfButtonText_hoover(&obj, minesweeper->start->leave, &leave__hoover);
    if (mySfButtonText_click(&obj, minesweeper->start->leave, event,
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
        draw(minesweeper, 3, &draw_background, &draw_start, &draw_cursor);
        get_event(minesweeper, 6, &close_window_event,
        &dig_animation_event, &mute_musics_event, &manage_musics_event,
        &start_startEvent, &start_leaveEvent);
        dig_animation(minesweeper);
        sfRenderWindow_display(__renderWindow__);
    }
    destroy_start(minesweeper);
}
