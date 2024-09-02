#include "../include/minesweeper.h"

void init_start(minesweeper_t *minesweeper)
{
    minesweeper->start = malloc(sizeof(start_t));
    minesweeper->start->minesweeper_name = mySfText_create(__mainFont__,
    "MineSweeper", sfWhite, VERY_BIG);
    sfText_setPosition(minesweeper->start->minesweeper_name, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 4});
    minesweeper->start->start = mySfText_create(__mainFont__,
    "Start", sfWhite, MEDIUM);
    mySfText_setOrigin(minesweeper->start->start, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->start, (sfVector2f)
    {__windowSize__.x / 20, __windowSize__.y / 2});
    minesweeper->start->leave = mySfText_create(__mainFont__,
    "Leave", sfWhite, MEDIUM);
    mySfText_setOrigin(minesweeper->start->leave, CENTER_LEFT);
    sfText_setPosition(minesweeper->start->leave, (sfVector2f)
    {__windowSize__.x / 20, __windowSize__.y / 1.5});
    minesweeper->start->start_minesweeper = false;
}

void destroy_start(minesweeper_t *minesweeper)
{
    mySfText_destroy(minesweeper->start->minesweeper_name);
    mySfText_destroy(minesweeper->start->start);
    mySfText_destroy(minesweeper->start->leave);
    free(minesweeper->start);
}

void start_startEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, __videoMode__};

    if (mySfButtonText_isNormal(&obj, minesweeper->start->start)) {
        sfText_setFillColor(minesweeper->start->start, sfWhite);
        sfText_setCharacterSize(minesweeper->start->start, MEDIUM);
    }
    if (mySfButtonText_isHoover(&obj, minesweeper->start->start)) {
        sfText_setFillColor(minesweeper->start->start, sfLightGrey);
        sfText_setCharacterSize(minesweeper->start->start, 50);
    }
    if (mySfButtonText_isLeftClick(&obj, minesweeper->start->start, event)) {
        sfText_setFillColor(minesweeper->start->start, sfDarkGrey);
        sfText_setCharacterSize(minesweeper->start->start, 45);
        sfSound_play(minesweeper->sounds->breaking_sound->sound);
        minesweeper->start->start_minesweeper = true;
    }
}

void start_leaveEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, __videoMode__};

    if (mySfButtonText_isNormal(&obj, minesweeper->start->leave)) {
        sfText_setFillColor(minesweeper->start->leave, sfWhite);
        sfText_setCharacterSize(minesweeper->start->leave, MEDIUM);
    }
    if (mySfButtonText_isHoover(&obj, minesweeper->start->leave)) {
        sfText_setFillColor(minesweeper->start->leave, sfLightGrey);
        sfText_setCharacterSize(minesweeper->start->leave, 50);
    }
    if (mySfButtonText_isLeftClick(&obj, minesweeper->start->leave, event)) {
        sfText_setFillColor(minesweeper->start->leave, sfDarkGrey);
        sfText_setCharacterSize(minesweeper->start->leave, 45);
        sfSound_play(minesweeper->sounds->breaking_sound->sound);
        sfRenderWindow_close(__renderWindow__);
    }
}

void start(minesweeper_t *minesweeper)
{
    init_start(minesweeper);
    while (sfRenderWindow_isOpen(__renderWindow__) &&
    !minesweeper->start->start_minesweeper) {
        sfRenderWindow_clear(__renderWindow__, sfGrey);
        draw(minesweeper, 2, &draw_background, &draw_start);
        get_event(minesweeper, 6, &close_window_event, &dig_event,
        &mute_musics_event, &manage_musics_event, &start_startEvent,
        &start_leaveEvent);
        sfRenderWindow_display(__renderWindow__);
    }
    destroy_start(minesweeper);
}
