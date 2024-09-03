#include "../include/minesweeper.h"

box_t **generate_grid(minesweeper_t *minesweeper)
{
    int **ref = minesweeper->map;
    unsigned int x = minesweeper->width;
    unsigned int y = minesweeper->height;
    box_t **grid = malloc(sizeof(box_t *) * y);

    for (unsigned int i = 0; i < y; i++) {
        grid[i] = malloc(sizeof(box_t) * x);
        for (unsigned int j = 0; j < x; j++)
            grid[i][j] = *init_box(minesweeper, HIDDEN, ref[i][j]);
    }
    return grid;
}

void set_grid(minesweeper_t *minesweeper)
{
    float scale = 1.2;
    sfVector2f box_size =
    {minesweeper->game->default_box_size.x * (scale / 30.0), minesweeper->game->default_box_size.y * (scale / 30.0)};
    sfVector2f grid_size =
    {box_size.x * minesweeper->width + 3 * (minesweeper->width - 1),
    box_size.y * minesweeper->height + 3 * (minesweeper->height - 1)};
    sfVector2f pos;

    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            pos.x = __windowSize__.x / 2 + (box_size.x + 3) * j -
            grid_size.x / 2.0;
            pos.y = __windowSize__.y / 2 + (box_size.y + 3) * i -
            grid_size.y / 2.0 + box_size.y;
            set_box(&minesweeper->game->grid[i][j], pos, scale);
        }
    }
}

void draw_grid(minesweeper_t *minesweeper)
{
    for (int i = 0; i < minesweeper->height; i++)
        for (int j = 0; j < minesweeper->width; j++)
            draw_box(minesweeper, &minesweeper->game->grid[i][j]);
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
