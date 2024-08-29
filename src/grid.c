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
    box_t **grid = minesweeper->game->grid;
    float scale = 2.0;
    float box_size = sfSprite_getGlobalBounds(minesweeper->game->grid[0][0].
    rockSprite->sprite).width * (scale / 30.0);
    unsigned int x = minesweeper->width;
    unsigned int y = minesweeper->height;
    sfVector2f default_pos = {box_size / 2.0, box_size / 2.0};
    sfVector2f pos;

    for (unsigned int i = 0; i < y; i++) {
        for (unsigned int j = 0; j < x; j++) {
            pos.x = default_pos.x + (box_size + 3) * j;
            pos.y = default_pos.y + (box_size + 3) * i;
            set_box(&grid[i][j], pos, scale);
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
