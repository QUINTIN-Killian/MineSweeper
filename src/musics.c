#include "../include/minesweeper.h"

void init_musics(minesweeper_t *minesweeper)
{
    minesweeper->musics = malloc(sizeof(musics_t));
    minesweeper->musics->main_music =
    mySfMusic_create("musics/main_music_theme.wav", sfTrue, sfFalse /*remettre sfTrue !!!*/);
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

void destroy_musics(minesweeper_t *minesweeper)
{
    mySfMusic_destroy(minesweeper->musics->main_music);
    free(minesweeper->musics);
}
