#include "../include/minesweeper.h"

void start_screen(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window->infos)) {
        sfRenderWindow_clear(game->window->infos, sfCyan);
        draw_background(game);
        draw_cursor(game);
        get_event(game, 5, &change_cursor_event, &close_window_event,
        &dig_animation_event, &mute_musics_event, &manage_musics_event);
        dig_animation(game);
        sfRenderWindow_display(game->window->infos);
    }
}
