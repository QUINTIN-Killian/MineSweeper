#include "../include/minesweeper.h"

void init_sounds(game_t *game)
{
    game->mining = malloc(sizeof(sounds_t));
    game->mining->mining_sound = sfSound_create();
    game->mining->mining_buffer =
    sfSoundBuffer_createFromFile("sounds/MiningSoundEffect.wav");
    sfSound_setBuffer(game->mining->mining_sound, game->mining->mining_buffer);
}

void destroy_sounds(game_t *game)
{
    sfSoundBuffer_destroy(game->mining->mining_buffer);
    sfSound_destroy(game->mining->mining_sound);
    free(game->mining);
}
