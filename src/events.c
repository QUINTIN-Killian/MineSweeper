#include "../include/minesweeper.h"

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

void start_startEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    if (mySfButtonText_isNormal(&__windowInfos__, minesweeper->start->start)) {
        sfText_setFillColor(minesweeper->start->start, sfWhite);
        sfText_setCharacterSize(minesweeper->start->start, MEDIUM);
    }
    if (mySfButtonText_isHoover(&__windowInfos__, minesweeper->start->start)) {
        sfText_setFillColor(minesweeper->start->start, sfLightGrey);
        sfText_setCharacterSize(minesweeper->start->start, 50);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__, minesweeper->start->start,
    event)) {
        sfText_setFillColor(minesweeper->start->start, sfDarkGrey);
        sfText_setCharacterSize(minesweeper->start->start, 45);
        sfSound_play(minesweeper->sounds->breaking_sound->sound);
        minesweeper->start->start_minesweeper = true;
    }
}

void start_leaveEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    if (mySfButtonText_isNormal(&__windowInfos__, minesweeper->start->leave)) {
        sfText_setFillColor(minesweeper->start->leave, sfWhite);
        sfText_setCharacterSize(minesweeper->start->leave, MEDIUM);
    }
    if (mySfButtonText_isHoover(&__windowInfos__, minesweeper->start->leave)) {
        sfText_setFillColor(minesweeper->start->leave, sfLightGrey);
        sfText_setCharacterSize(minesweeper->start->leave, 50);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__, minesweeper->start->leave,
    event)) {
        sfText_setFillColor(minesweeper->start->leave, sfDarkGrey);
        sfText_setCharacterSize(minesweeper->start->leave, 45);
        sfSound_play(minesweeper->sounds->breaking_sound->sound);
        sfRenderWindow_close(__renderWindow__);
    }
}

void manage_musics_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfMusic_setVolume(minesweeper->musics->main_music,
        sfMusic_getVolume(minesweeper->musics->main_music) + 5.0);
    }
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfMusic_setVolume(minesweeper->musics->main_music,
        sfMusic_getVolume(minesweeper->musics->main_music) - 5.0);
    }
}

void mute_musics_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sfMusic_getStatus(minesweeper->musics->main_music) == sfPlaying)
            sfMusic_pause(minesweeper->musics->main_music);
        else
            sfMusic_play(minesweeper->musics->main_music);
    }
}

void game_boxEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            if (mySfButtonRectangle_isLeftClick(&__windowInfos__,
            minesweeper->game->grid[i][j].rectangle, event) &&
            minesweeper->game->grid[i][j].state == HIDDEN)
                return mine(minesweeper, j, i);
            if (mySfButtonRectangle_isRightClick(&__windowInfos__,
            minesweeper->game->grid[i][j].rectangle, event) &&
            minesweeper->game->grid[i][j].state == FLAGED)
                return unflag(minesweeper, j, i);
            if (mySfButtonRectangle_isRightClick(&__windowInfos__,
            minesweeper->game->grid[i][j].rectangle, event) &&
            minesweeper->game->grid[i][j].state == HIDDEN)
                return flag(minesweeper, j, i);
        }
    }
}

void get_event(minesweeper_t *minesweeper, int nb_events, ...)
{
    sfEvent event;
    va_list args;
    va_list args_cpy;
    void (*event_func)(minesweeper_t *, sfEvent *) = NULL;

    va_start(args, nb_events);
    while (sfRenderWindow_pollEvent(__renderWindow__, &event)) {
        va_copy(args_cpy, args);
        for (int i = 0; i < nb_events; i++) {
            event_func = va_arg(args_cpy,
            void (*)(minesweeper_t *, sfEvent *));
            if (event_func)
                event_func(minesweeper, &event);
        }
        va_end(args_cpy);
    }
    va_end(args);
}
