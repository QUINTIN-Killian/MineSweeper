#include "../include/minesweeper.h"

void close_window_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtClosed ||
    sfKeyboard_isKeyPressed(sfKeyEscape)) {
        sfRenderWindow_close(game->window->infos);
    }
}

void change_cursor_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyC)) {
        game->cursor->pickaxe_cursor = !game->cursor->pickaxe_cursor;
        sfRenderWindow_setMouseCursorVisible(game->window->infos,
        !game->cursor->pickaxe_cursor);
    }
}

void dig_animation_event(game_t *game, sfEvent *event)
{
    if (game->cursor->pickaxe_cursor && event->type == sfEvtMouseButtonPressed
    && sfMouse_isButtonPressed(sfMouseLeft)) {
        game->cursor->state = DIG;
        sfSound_play(game->sounds->mining_sound->sound);
    }
}

void mute_musics_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeySpace)) {
        if (sfMusic_getStatus(game->musics->main_music) == sfPlaying)
            sfMusic_pause(game->musics->main_music);
        else
            sfMusic_play(game->musics->main_music);
    }
}

void manage_musics_event(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyUp)) {
        sfMusic_setVolume(game->musics->main_music,
        sfMusic_getVolume(game->musics->main_music) + 5.0);
    }
    if (event->type == sfEvtKeyPressed &&
    sfKeyboard_isKeyPressed(sfKeyDown)) {
        sfMusic_setVolume(game->musics->main_music,
        sfMusic_getVolume(game->musics->main_music) - 5.0);
    }
}

void get_event(game_t *game, int nb_events, ...)
{
    sfEvent event;
    va_list args;
    va_list args_cpy;
    void (*event_func)(game_t *, sfEvent *) = NULL;

    va_start(args, nb_events);
    while (sfRenderWindow_pollEvent(game->window->infos, &event)) {
        va_copy(args_cpy, args);
        for (int i = 0; i < nb_events; i++) {
            event_func = va_arg(args_cpy, void (*)(game_t *, sfEvent *));
            if (event_func)
                event_func(game, &event);
        }
        va_end(args_cpy);
    }
    va_end(args);
}
