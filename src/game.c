#include "../include/minesweeper.h"

void game_screen(game_t *game)
{
    while (sfRenderWindow_isOpen(__renderWindow__)) {
        sfRenderWindow_clear(__renderWindow__, sfCyan);
        draw_background(game);
        draw_cursor(game);
        get_event(game, 4, &close_window_event, &dig_animation_event,
        &mute_musics_event, &manage_musics_event);
        dig_animation(game);
        sfRenderWindow_display(__renderWindow__);
    }
}
