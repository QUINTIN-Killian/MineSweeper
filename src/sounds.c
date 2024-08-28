#include "../include/minesweeper.h"

void init_sounds(minesweeper_t *minesweeper)
{
    minesweeper->sounds = malloc(sizeof(sounds_t));
    minesweeper->sounds->mining_sound =
    mySfSoundCreate("sounds/MiningSoundEffect.wav");
    minesweeper->sounds->breaking_sound = mySfSoundCreate("sounds/RockDestroyed.wav");
}

void destroy_sounds(minesweeper_t *minesweeper)
{
    mySfSoundDestroy(minesweeper->sounds->mining_sound);
    mySfSoundDestroy(minesweeper->sounds->breaking_sound);
    free(minesweeper->sounds);
}
