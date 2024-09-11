#include "../include/minesweeper.h"

void pause_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        if (minesweeper->game->clock->pause) {
            mySfClock_unpause(minesweeper->game->clock);
            minesweeper->screen = GAME;
        } else {
            mySfClock_pause(minesweeper->game->clock);
            minesweeper->screen = PAUSE;
        }
    }
}

void pause_continueEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    sfVector2f size;

    if (!minesweeper->game->clock->pause)
        return;
    size = (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 1.1};
    if (mySfButtonText_isNormal(&__windowInfos__,
    minesweeper->pause->resume)) {
        sfText_setFillColor(minesweeper->pause->resume, sfWhite);
        sfText_setCharacterSize(minesweeper->pause->resume, H7);
    }
    if (mySfButtonText_isHoover(&__windowInfos__,
    minesweeper->pause->resume)) {
        sfText_setFillColor(minesweeper->pause->resume, sfLightGrey);
        sfText_setCharacterSize(minesweeper->pause->resume, H5);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__,
    minesweeper->pause->resume, event)) {
        sfText_setFillColor(minesweeper->pause->resume, sfWhite);
        sfText_setCharacterSize(minesweeper->pause->resume, H7);
        mySfClock_unpause(minesweeper->game->clock);
        minesweeper->screen = GAME;
    }
    mySfText_setOrigin(minesweeper->pause->resume, CENTER);
    sfText_setPosition(minesweeper->pause->resume,
    (sfVector2f){__windowSize__.x / 2, size.y / 2});
}

void pause_restartEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    sfVector2f size;

    if (!minesweeper->game->clock->pause)
        return;
    size = (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 1.1};
    if (mySfButtonText_isNormal(&__windowInfos__,
    minesweeper->pause->restart)) {
        sfText_setFillColor(minesweeper->pause->restart, sfWhite);
        sfText_setCharacterSize(minesweeper->pause->restart, H7);
    }
    if (mySfButtonText_isHoover(&__windowInfos__,
    minesweeper->pause->restart)) {
        sfText_setFillColor(minesweeper->pause->restart, sfLightGrey);
        sfText_setCharacterSize(minesweeper->pause->restart, H5);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__,
    minesweeper->pause->restart, event)) {
        sfText_setFillColor(minesweeper->pause->restart, sfWhite);
        sfText_setCharacterSize(minesweeper->pause->restart, H7);
        mySfClock_unpause(minesweeper->game->clock);
        minesweeper->bombs_left = minesweeper->total_bombs;
        minesweeper->box_left = minesweeper->total_box;
        reset_map(minesweeper);
        reset_game(minesweeper);
        minesweeper->screen = GAME;
    }
    mySfText_setOrigin(minesweeper->pause->restart, CENTER);
    sfText_setPosition(minesweeper->pause->restart,
    (sfVector2f){__windowSize__.x / 2, size.y / 1.5});
}

void pause_mainMenuEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    sfVector2f size;

    if (!minesweeper->game->clock->pause)
        return;
    size = (sfVector2f){__windowSize__.x / 2, __windowSize__.y / 1.1};
    if (mySfButtonText_isNormal(&__windowInfos__,
    minesweeper->pause->main_menu)) {
        sfText_setFillColor(minesweeper->pause->main_menu, sfWhite);
        sfText_setCharacterSize(minesweeper->pause->main_menu, H7);
    }
    if (mySfButtonText_isHoover(&__windowInfos__,
    minesweeper->pause->main_menu)) {
        sfText_setFillColor(minesweeper->pause->main_menu, sfLightGrey);
        sfText_setCharacterSize(minesweeper->pause->main_menu, H5);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__,
    minesweeper->pause->main_menu, event)) {
        sfText_setFillColor(minesweeper->pause->main_menu, sfWhite);
        sfText_setCharacterSize(minesweeper->pause->main_menu, H7);
        mySfClock_unpause(minesweeper->game->clock);
        minesweeper->screen = START;
    }
    mySfText_setOrigin(minesweeper->pause->main_menu, CENTER);
    sfText_setPosition(minesweeper->pause->main_menu,
    (sfVector2f){__windowSize__.x / 2, size.y / 1.2});
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
    if (event->type == sfEvtClosed) {
        sfRenderWindow_close(__renderWindow__);
    }
}

void start_startEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    if (mySfButtonText_isNormal(&__windowInfos__, minesweeper->start->start)) {
        sfText_setFillColor(minesweeper->start->start, sfWhite);
        sfText_setCharacterSize(minesweeper->start->start, H7);
    }
    if (mySfButtonText_isHoover(&__windowInfos__, minesweeper->start->start)) {
        sfText_setFillColor(minesweeper->start->start, sfLightGrey);
        sfText_setCharacterSize(minesweeper->start->start, H5);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__, minesweeper->start->start,
    event)) {
        sfText_setFillColor(minesweeper->start->start, sfWhite);
        sfText_setCharacterSize(minesweeper->start->start, H7);
        minesweeper->screen = GAME;
        minesweeper->bombs_left = minesweeper->total_bombs;
        minesweeper->box_left = minesweeper->total_box;
        reset_map(minesweeper);
        reset_game(minesweeper);
    }
}

void start_leaveEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    if (mySfButtonText_isNormal(&__windowInfos__, minesweeper->start->leave)) {
        sfText_setFillColor(minesweeper->start->leave, sfWhite);
        sfText_setCharacterSize(minesweeper->start->leave, H7);
    }
    if (mySfButtonText_isHoover(&__windowInfos__, minesweeper->start->leave)) {
        sfText_setFillColor(minesweeper->start->leave, sfLightGrey);
        sfText_setCharacterSize(minesweeper->start->leave, H5);
    }
    if (mySfButtonText_isLeftClick(&__windowInfos__, minesweeper->start->leave,
    event)) {
        sfText_setFillColor(minesweeper->start->leave, sfWhite);
        sfText_setCharacterSize(minesweeper->start->leave, H7);
        sfRenderWindow_close(__renderWindow__);
    }
}

void start_changeDifficultyEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    if (mySfButtonText_isNormal(&__windowInfos__,
    minesweeper->start->change_difficulty))
        sfText_setFillColor(minesweeper->start->change_difficulty, sfWhite);
    if (mySfButtonText_isHoover(&__windowInfos__,
    minesweeper->start->change_difficulty))
        sfText_setFillColor(minesweeper->start->change_difficulty,
        sfLightGrey);
    if (mySfButtonText_isLeftClick(&__windowInfos__,
    minesweeper->start->change_difficulty, event)) {
        sfText_setFillColor(minesweeper->start->change_difficulty, sfDarkGrey);
        change_difficulty(minesweeper);
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
