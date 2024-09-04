#include "../include/minesweeper.h"

void init_game(minesweeper_t *minesweeper)
{
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->default_box_size = (sfVector2f){626, 626};
    minesweeper->game->grid = generate_grid(minesweeper);
    set_grid(minesweeper);
    minesweeper->game->timer = mySfText_create(__mainFont__,
    NULL, sfLightGrey, SMALL);
    sfText_setPosition(minesweeper->game->timer, (sfVector2f)
    {__windowSize__.x / 100, __windowSize__.y / 100});
    minesweeper->game->clock = sfClock_create();
}

void destroy_game(minesweeper_t *minesweeper)
{
    destroy_grid(minesweeper);
    sfClock_destroy(minesweeper->game->clock);
    mySfText_destroy(minesweeper->game->timer);
}

bool victory(minesweeper_t *minesweeper)
{
    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            if (minesweeper->game->grid[i][j].state != REVEALED &&
            minesweeper->game->grid[i][j].type != BOMB)
                return false;
        }
    }
    return true;
}

void mine(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->breaking_sound->sound);
    if (minesweeper->game->grid[y][x].type == BOMB) {
        sfSound_play(minesweeper->sounds->explosion_sound->sound);
        reveal_grid(minesweeper);
    } else {
        reveal_boxes(minesweeper, x, y);
        if (victory(minesweeper))
            return;
            //save best score in a file here !
    }
}


void flag(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->flag_sound->sound);
    minesweeper->game->grid[y][x].state = FLAGED;
    minesweeper->bombs_left--;
}

void unflag(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->flag_sound->sound);
    minesweeper->game->grid[y][x].state = HIDDEN;
    minesweeper->bombs_left++;
}
