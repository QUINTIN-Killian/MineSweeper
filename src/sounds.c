#include "../include/minesweeper.h"

void init_sounds(game_t *game)
{
    game->sounds = malloc(sizeof(sounds_t));
    game->sounds->mining_sound = sfSound_create();
    game->sounds->mining_buffer =
    sfSoundBuffer_createFromFile("sounds/MiningSoundEffect.wav");
    sfSound_setBuffer(game->sounds->mining_sound, game->sounds->mining_buffer);
    game->sounds->breaking_sound = sfSound_create();
    game->sounds->breaking_buffer =
    sfSoundBuffer_createFromFile("sounds/RockDestroyed.wav");
    sfSound_setBuffer(game->sounds->breaking_sound,
    game->sounds->breaking_buffer);
}

void destroy_sounds(game_t *game)
{
    sfSoundBuffer_destroy(game->sounds->mining_buffer);
    sfSound_destroy(game->sounds->mining_sound);
    sfSoundBuffer_destroy(game->sounds->breaking_buffer);
    sfSound_destroy(game->sounds->breaking_sound);
    free(game->sounds);
}
