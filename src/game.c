#include "../include/minesweeper.h"

static void init_game(minesweeper_t *minesweeper)
{
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->grid = generate_grid(minesweeper);
    set_grid(minesweeper);
}

static void destroy_game(minesweeper_t *minesweeper)
{
    destroy_grid(minesweeper);
}

void game(minesweeper_t *minesweeper)
{
    init_game(minesweeper);
    while (sfRenderWindow_isOpen(__renderWindow__)) {
        sfRenderWindow_clear(__renderWindow__, sfCyan);
        draw(minesweeper, 3, &draw_background, &draw_grid, &draw_cursor);
        get_event(minesweeper, 4, &close_window_event, &dig_animation_event,
        &mute_musics_event, &manage_musics_event);
        dig_animation(minesweeper);
        sfRenderWindow_display(__renderWindow__);
    }
    destroy_game(minesweeper);
}
