#include "../include/minesweeper.h"

void game(minesweeper_t *minesweeper)
{
    while (sfRenderWindow_isOpen(__renderWindow__)) {
        sfRenderWindow_clear(__renderWindow__, sfCyan);
        draw_background(minesweeper);
        draw_cursor(minesweeper);
        get_event(minesweeper, 4, &close_window_event, &dig_animation_event,
        &mute_musics_event, &manage_musics_event);
        dig_animation(minesweeper);
        sfRenderWindow_display(__renderWindow__);
    }
}
