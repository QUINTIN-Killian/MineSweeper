#include "../include/minesweeper.h"

void switch_boxes(minesweeper_t *minesweeper, int x, int y, boxType_t type)
{
    boxType_t box_clicked_type = minesweeper->map[y][x];
    sfVector2i switch_coords = {randint(0, minesweeper->width - 1),
    randint(0, minesweeper->height - 1)};
    int src_type = (int)type;

    while (minesweeper->map[switch_coords.y][switch_coords.x] != src_type ||
    (switch_coords.x >= x - 1 && switch_coords.x <= x + 1 &&
    switch_coords.y >= y - 1 && switch_coords.y <= y + 1)) {
        switch_coords = (sfVector2i){randint(0, minesweeper->width - 1),
        randint(0, minesweeper->height - 1)};
    }
    minesweeper->map[y][x] =
    minesweeper->map[switch_coords.y][switch_coords.x];
    minesweeper->map[switch_coords.y][switch_coords.x] = box_clicked_type;
}

static void first_play_manager(minesweeper_t *minesweeper, int x, int y)
{
    if (minesweeper->game->grid[y][x].type == VOID)
        return;
    switch_boxes(minesweeper, x, y, VOID);
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (!is_in_range_grid(minesweeper->width,
            minesweeper->height, j, i) || (j == x && i == y))
                continue;
            if (minesweeper->game->grid[i][j].type == BOMB)
                switch_boxes(minesweeper, j, i, VOID);
        }
    }
    set_map_values(minesweeper);
    for (int i = 0; i < minesweeper->height; i++)
        for (int j = 0; j < minesweeper->width; j++)
            minesweeper->game->grid[i][j].type = minesweeper->map[i][j];
}

void mine(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->breaking_sound->sound);
    if (minesweeper->game->first_play) {
        first_play_manager(minesweeper, x, y);
        minesweeper->game->first_play = false;
    }
    if (minesweeper->game->grid[y][x].type == BOMB) {
        sfSound_play(minesweeper->sounds->explosion_sound->sound);
        reveal_grid(minesweeper);
        minesweeper->screen = END;
    } else
        reveal_box(minesweeper, x, y);
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

void set_victory(minesweeper_t *minesweeper)
{
    if (minesweeper->box_left == minesweeper->total_bombs &&
    minesweeper->bombs_left == 0) {
        minesweeper->victory = true;
        minesweeper->screen = END;
        mini_printf("VICTORY !\n");
        //save best score in a file here !
    }
}
