#include "../include/minesweeper.h"

void init_sounds(minesweeper_t *minesweeper)
{
    minesweeper->sounds = malloc(sizeof(sounds_t));
    minesweeper->sounds->mining_sound =
    mySfSound_create("sounds/MiningSoundEffect.wav");
    minesweeper->sounds->breaking_sound =
    mySfSound_create("sounds/RockDestroyed.wav");
    minesweeper->sounds->flag_sound =
    mySfSound_create("sounds/FlagPlaced.wav");
    sfSound_setVolume(minesweeper->sounds->flag_sound->sound, 50.0);
    minesweeper->sounds->explosion_sound =
    mySfSound_create("sounds/Explosion.wav");
}

void destroy_sounds(minesweeper_t *minesweeper)
{
    mySfSound_destroy(minesweeper->sounds->mining_sound);
    mySfSound_destroy(minesweeper->sounds->breaking_sound);
    mySfSound_destroy(minesweeper->sounds->flag_sound);
    mySfSound_destroy(minesweeper->sounds->explosion_sound);
    free(minesweeper->sounds);
}
