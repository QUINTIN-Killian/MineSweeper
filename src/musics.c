#include "../include/minesweeper.h"

void init_musics(game_t *game)
{
    game->musics = malloc(sizeof(musics_t));
    game->musics->main_music =
    mySfMusicCreate("musics/main_music_theme.wav", sfTrue, sfFalse /*remettre sfTrue !!!*/);
}

void destroy_musics(game_t *game)
{
    mySfMusicDestroy(game->musics->main_music);
    free(game->musics);
}
