#include "../include/minesweeper.h"

void (*screens_tab[])(minesweeper_t *) = {
    credits_screen,
    start_screen,
    game_screen,
    pause_screen,
    end_screen
};

void credits_screen(minesweeper_t *minesweeper)
{
    sfColor color;

    init_credits(minesweeper);
    get_event(minesweeper, 3, &close_window_event, &mute_musics_event,
    &manage_musics_event);
    sfRenderWindow_drawText(__renderWindow__,
    minesweeper->credits->credits_text, NULL);
    color = sfText_getColor(minesweeper->credits->credits_text);
    if (minesweeper->credits->show)
        color.a += 1;
    else
        color.a -= 1;
    sfText_setColor(minesweeper->credits->credits_text, color);
    if (color.a == 255)
        minesweeper->credits->show = false;
    if (color.a == 0)
        minesweeper->screen = START;
}

void start_screen(minesweeper_t *minesweeper)
{
    init_start(minesweeper);
    draw(minesweeper, 2, &draw_background, &draw_start);
    get_event(minesweeper, 7, &close_window_event, &dig_event,
    &mute_musics_event, &manage_musics_event, &start_startEvent,
    &start_leaveEvent, &start_changeDifficultyEvent);
}

void game_screen(minesweeper_t *minesweeper)
{
    init_game(minesweeper);
    draw(minesweeper, 4, &draw_background, &draw_grid, &draw_timer,
    &draw_game);
    get_event(minesweeper, 6, &close_window_event, &dig_event,
    &mute_musics_event, &manage_musics_event, &game_boxEvent, &pause_event);
}

void pause_screen(minesweeper_t *minesweeper)
{
    init_pause(minesweeper);
    draw(minesweeper, 5, &draw_background, &draw_grid, &draw_timer, &draw_game,
    &draw_pause);
    get_event(minesweeper, 7, &close_window_event, &dig_event,
    &mute_musics_event, &manage_musics_event, &pause_continueEvent,
    &pause_restartEvent, &pause_mainMenuEvent);
}

void end_screen(minesweeper_t *minesweeper)
{
    init_end(minesweeper);
    draw(minesweeper, 5, &draw_background, &draw_grid, &draw_timer, &draw_game,
    &draw_end);
    get_event(minesweeper, 6, &close_window_event, &dig_event,
    &mute_musics_event, &manage_musics_event, &end_restartEvent,
    &end_mainMenuEvent);
}

static void sideScreens_destroy(minesweeper_t *minesweeper)
{
    if (minesweeper->screen != CREDITS)
        destroy_credits(minesweeper);
    if (minesweeper->screen != START)
        destroy_start(minesweeper);
    if (minesweeper->screen != GAME && minesweeper->screen != PAUSE &&
    minesweeper->screen != END)
        destroy_game(minesweeper);
    if (minesweeper->screen != END)
        destroy_end(minesweeper);
}

void screen_manager(minesweeper_t *minesweeper)
{
    while (sfRenderWindow_isOpen(__renderWindow__)) {
        sfRenderWindow_clear(__renderWindow__, sfBlack);
        screens_tab[minesweeper->screen](minesweeper);
        sfRenderWindow_display(__renderWindow__);
        sideScreens_destroy(minesweeper);
    }
}
