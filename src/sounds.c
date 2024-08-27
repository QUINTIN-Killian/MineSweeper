#include "../include/minesweeper.h"

void init_sounds(game_t *game)
{
    game->sounds = malloc(sizeof(sounds_t));
    game->sounds->mining_sound =
    mySfSoundCreate("sounds/MiningSoundEffect.wav");
    game->sounds->breaking_sound = mySfSoundCreate("sounds/RockDestroyed.wav");
}

void destroy_sounds(game_t *game)
{
    mySfSoundDestroy(game->sounds->mining_sound);
    mySfSoundDestroy(game->sounds->breaking_sound);
    free(game->sounds);
}
