#include "../include/minesweeper.h"

void init_musics(minesweeper_t *minesweeper)
{
    minesweeper->musics = malloc(sizeof(musics_t));
    minesweeper->musics->main_music =
    mySfMusic_create("musics/main_music_theme.wav", sfTrue, sfTrue);
}

void destroy_musics(minesweeper_t *minesweeper)
{
    mySfMusic_destroy(minesweeper->musics->main_music);
    free(minesweeper->musics);
}
