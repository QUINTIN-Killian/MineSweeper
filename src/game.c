#include "../include/minesweeper.h"

void reset_game(minesweeper_t *minesweeper)
{
    if (minesweeper->game == NULL)
        return;
    reset_grid(minesweeper);
    mySfClock_destroy(minesweeper->game->clock);
    minesweeper->game->clock = mySfClock_create();
    minesweeper->game->first_play = true;
    sfText_setString(minesweeper->game->bombs_left, ": 000");
}

void init_game(minesweeper_t *minesweeper)
{
    if (minesweeper->game != NULL)
        return;
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->default_box_size = (sfVector2f){626, 626};
    minesweeper->game->grid = create_grid(minesweeper);
    minesweeper->game->timer = mySfText_create(__mainFont__,
    NULL, sfWhite, SMALL);
    sfText_setPosition(minesweeper->game->timer, (sfVector2f)
    {__windowSize__.x / 100, __windowSize__.y / 100});
    minesweeper->game->clock = mySfClock_create();
    minesweeper->game->first_play = true;
    minesweeper->game->bomb = mySfSprite_create("images/Mine.png", sfFalse);
    sfSprite_setPosition(minesweeper->game->bomb->sprite,
    (sfVector2f){__windowSize__.x / 1.15, 0});
    sfSprite_setScale(minesweeper->game->bomb->sprite,
    (sfVector2f){BOX_SCALE * 4, BOX_SCALE * 4});
    minesweeper->game->bombs_left = mySfText_create(__mainFont__, ": 000",
    sfWhite, SMALL);
    mySfText_setOrigin(minesweeper->game->bombs_left, TOP_RIGHT);
    sfText_setPosition(minesweeper->game->bombs_left, (sfVector2f)
    {__windowSize__.x - __windowSize__.x / 100, __windowSize__.y / 100});
}

void destroy_game(minesweeper_t *minesweeper)
{
    if (minesweeper->game == NULL)
        return;
    mySfSprite_destroy(minesweeper->game->bomb);
    mySfText_destroy(minesweeper->game->bombs_left);
    destroy_grid(minesweeper);
    mySfClock_destroy(minesweeper->game->clock);
    mySfText_destroy(minesweeper->game->timer);
    destroy_pause(minesweeper);
    free(minesweeper->game);
    minesweeper->game = NULL;
}
