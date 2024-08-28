#include "../include/minesweeper.h"

void init_musics(minesweeper_t *minesweeper)
{
    minesweeper->musics = malloc(sizeof(musics_t));
    minesweeper->musics->main_music =
    mySfMusicCreate("musics/main_music_theme.wav", sfTrue, sfFalse /*remettre sfTrue !!!*/);
}

void destroy_musics(minesweeper_t *minesweeper)
{
    mySfMusicDestroy(minesweeper->musics->main_music);
    free(minesweeper->musics);
}
