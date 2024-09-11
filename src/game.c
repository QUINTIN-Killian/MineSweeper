#include "../include/minesweeper.h"

void set_game(minesweeper_t *minesweeper)
{
    if (minesweeper->game == NULL)
        return;
    set_grid(minesweeper);
    mySfClock_destroy(minesweeper->game->clock);
    minesweeper->game->clock = mySfClock_create();
    minesweeper->game->first_play = true;
    sfText_setString(minesweeper->game->bombs_left, ": 00");
}

void init_game(minesweeper_t *minesweeper)
{
    sfFloatRect bounds;

    if (minesweeper->game != NULL)
        return;
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->default_box_size = (sfVector2f){626, 626};
    minesweeper->game->grid = create_grid(minesweeper);
    minesweeper->game->timer = mySfText_create(__mainFont__,
    NULL, sfWhite, H8);
    sfText_setPosition(minesweeper->game->timer, (sfVector2f)
    {__windowSize__.x / 100, __windowSize__.y / 100});
    minesweeper->game->clock = mySfClock_create();
    minesweeper->game->first_play = true;
    minesweeper->game->bomb = mySfSprite_create("images/Mine.png", sfTrue);
    sfSprite_setScale(minesweeper->game->bomb->sprite,
    (sfVector2f){BOX_SCALE * 5, BOX_SCALE * 5});
    minesweeper->game->bombs_left = mySfText_create(__mainFont__, ": 00",
    sfWhite, H8);
    mySfText_setOrigin(minesweeper->game->bombs_left, TOP_RIGHT);
    sfText_setPosition(minesweeper->game->bombs_left, (sfVector2f)
    {__windowSize__.x - __windowSize__.x / 100, __windowSize__.y / 100});
    bounds = sfText_getGlobalBounds(minesweeper->game->bombs_left);
    sfSprite_setPosition(minesweeper->game->bomb->sprite, (sfVector2f)
    {__windowSize__.x - __windowSize__.x / 100 - bounds.width * 1.4,
    __windowSize__.y / 100 + bounds.height / 1.5});
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
