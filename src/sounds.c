#include "../include/minesweeper.h"

void init_sounds(minesweeper_t *minesweeper)
{
    minesweeper->sounds = malloc(sizeof(sounds_t));
    minesweeper->sounds->mining_sound =
    mySfSound_create("sounds/MiningSoundEffect.wav");
    minesweeper->sounds->breaking_sound = mySfSound_create("sounds/RockDestroyed.wav");
}

void destroy_sounds(minesweeper_t *minesweeper)
{
    mySfSound_destroy(minesweeper->sounds->mining_sound);
    mySfSound_destroy(minesweeper->sounds->breaking_sound);
    free(minesweeper->sounds);
}
