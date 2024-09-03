#include "../include/minesweeper.h"

void close_window_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtClosed ||
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(__renderWindow__);
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

void dig_event(minesweeper_t *minesweeper, sfEvent *event)
{
    if (event->type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft)) {
        sfSound_play(minesweeper->sounds->mining_sound->sound);
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
