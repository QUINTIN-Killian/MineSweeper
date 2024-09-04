#include "../include/minesweeper.h"

void credits(minesweeper_t *minesweeper)
{
    init_credits(minesweeper);
    while (sfRenderWindow_isOpen(__renderWindow__) &&
    sfText_getColor(minesweeper->credits->credits_text).a < 255) {
        sfRenderWindow_clear(__renderWindow__, sfBlack);
        get_event(minesweeper, 3, &close_window_event,
        &mute_musics_event, &manage_musics_event);
        sfRenderWindow_drawText(__renderWindow__,
        minesweeper->credits->credits_text, NULL);
        sfRenderWindow_display(__renderWindow__);
        sfText_setColor(minesweeper->credits->credits_text,(sfColor){255, 255,
        255, sfText_getColor(minesweeper->credits->credits_text).a + 1});
    }
    while (sfRenderWindow_isOpen(__renderWindow__) &&
    sfText_getColor(minesweeper->credits->credits_text).a > 0) {
        sfRenderWindow_clear(__renderWindow__, sfBlack);
        get_event(minesweeper, 3, &close_window_event,
        &mute_musics_event, &manage_musics_event);
        sfRenderWindow_drawText(__renderWindow__,
        minesweeper->credits->credits_text, NULL);
        sfRenderWindow_display(__renderWindow__);
        sfText_setColor(minesweeper->credits->credits_text,(sfColor){255, 255,
        255, sfText_getColor(minesweeper->credits->credits_text).a - 1});
    }
    destroy_credits(minesweeper);
}

void start(minesweeper_t *minesweeper)
{
    init_start(minesweeper);
    while (sfRenderWindow_isOpen(__renderWindow__) &&
    !minesweeper->start->start_minesweeper) {
        sfRenderWindow_clear(__renderWindow__, sfGrey);
        draw(minesweeper, 2, &draw_background, &draw_start);
        get_event(minesweeper, 6, &close_window_event, &dig_event,
        &mute_musics_event, &manage_musics_event, &start_startEvent,
        &start_leaveEvent);
        sfRenderWindow_display(__renderWindow__);
    }
    destroy_start(minesweeper);
}

void game(minesweeper_t *minesweeper)
{
    init_game(minesweeper);
    while (sfRenderWindow_isOpen(__renderWindow__)) {
        sfRenderWindow_clear(__renderWindow__, sfGrey);
        draw(minesweeper, 3, &draw_background, &draw_grid, &draw_timer);
        get_event(minesweeper, 5, &close_window_event, &dig_event,
        &mute_musics_event, &manage_musics_event, &game_boxEvent);
        sfRenderWindow_display(__renderWindow__);
    }
    destroy_game(minesweeper);
}
