#include "../include/minesweeper.h"

void init_game(minesweeper_t *minesweeper)
{
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->default_box_size = (sfVector2f){626, 626};
    minesweeper->game->grid = generate_grid(minesweeper);
    minesweeper->game->timer = mySfText_create(__mainFont__,
    NULL, sfLightGrey, SMALL);
    sfText_setPosition(minesweeper->game->timer, (sfVector2f)
    {__windowSize__.x / 100, __windowSize__.y / 100});
    minesweeper->game->clock = mySfClock_create();
    minesweeper->game->first_play = true;
    init_pause(minesweeper);
}

void destroy_game(minesweeper_t *minesweeper)
{
    destroy_grid(minesweeper);
    mySfClock_destroy(minesweeper->game->clock);
    mySfText_destroy(minesweeper->game->timer);
    destroy_pause(minesweeper);
}
