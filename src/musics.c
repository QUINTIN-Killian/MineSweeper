#include "../include/minesweeper.h"

void init_musics(game_t *game)
{
    game->musics = malloc(sizeof(musics_t));
    game->musics->main_music =
    sfMusic_createFromFile("musics/main_music_theme.wav");
    sfMusic_setLoop(game->musics->main_music, sfTrue);
    //sfMusic_play(game->musics->main_music);
}

void destroy_musics(game_t *game)
{
    sfMusic_stop(game->musics->main_music);
    sfMusic_destroy(game->musics->main_music);
    free(game->musics);
}
