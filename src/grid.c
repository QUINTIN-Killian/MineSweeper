#include "../include/minesweeper.h"

box_t **create_grid(minesweeper_t *minesweeper)
{
    box_t **grid = malloc(sizeof(box_t *) * minesweeper->height);
    sfVector2f box_size = {minesweeper->game->default_box_size.x * BOX_SCALE,
    minesweeper->game->default_box_size.y * BOX_SCALE};
    sfVector2f grid_size = {box_size.x * minesweeper->width + 3 *
    (minesweeper->width - 1), box_size.y * minesweeper->height + 3 *
    (minesweeper->height - 1)};
    sfVector2f pos;

    for (int i = 0; i < minesweeper->height; i++) {
        grid[i] = malloc(sizeof(box_t) * minesweeper->width);
        for (int j = 0; j < minesweeper->width; j++) {
            pos.x = __windowSize__.x / 2.0 + (box_size.x + 3.0) * j -
            grid_size.x / 2.0;
            pos.y = __windowSize__.y / 2.0 + (box_size.y + 3.0) * i -
            grid_size.y / 2.0 + box_size.y;
            grid[i][j] = init_box(minesweeper, HIDDEN,
            minesweeper->map[i][j], pos);
        }
    }
    return grid;
}

void reset_grid(minesweeper_t *minesweeper)
{
    sfVector2f box_size = {minesweeper->game->default_box_size.x * BOX_SCALE,
    minesweeper->game->default_box_size.y * BOX_SCALE};
    sfVector2f grid_size = {box_size.x * minesweeper->width + 3 *
    (minesweeper->width - 1), box_size.y * minesweeper->height + 3 *
    (minesweeper->height - 1)};
    sfVector2f pos;

    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            pos.x = __windowSize__.x / 2.0 + (box_size.x + 3.0) * j -
            grid_size.x / 2.0;
            pos.y = __windowSize__.y / 2.0 + (box_size.y + 3.0) * i -
            grid_size.y / 2.0 + box_size.y;
            destroy_box(&minesweeper->game->grid[i][j]);
            minesweeper->game->grid[i][j] = init_box(minesweeper, HIDDEN,
            minesweeper->map[i][j], pos);
        }
    }
}

void reveal_grid(minesweeper_t *minesweeper)
{
    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            if (minesweeper->game->grid[i][j].state != REVEALED)
                set_box(minesweeper, &minesweeper->game->grid[i][j]);
            if (minesweeper->game->grid[i][j].type == BOMB)
                sfRectangleShape_setFillColor(minesweeper->game->
                grid[i][j].rectangle, sfRed);
        }
    }
}

void destroy_grid(minesweeper_t *minesweeper)
{
    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++)
            destroy_box(&minesweeper->game->grid[i][j]);
        free(minesweeper->game->grid[i]);
    }
    free(minesweeper->game->grid);
}

bool is_in_range_grid(int width, int height, int x, int y)
{
    return (y >= 0 && y < height && x >= 0 && x < width);
}
