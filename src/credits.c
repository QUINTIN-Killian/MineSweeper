#include "../include/minesweeper.h"

static void init_credits(minesweeper_t *minesweeper)
{
    minesweeper->credits = malloc(sizeof(credits_t));
    minesweeper->credits->credits_text = mySfText_create(__mainFont__,
    "minesweeper created by Killian QUINTIN",
    (sfColor){255, 255, 255, 0}, NONE);
    sfText_setPosition(minesweeper->credits->credits_text, (sfVector2f)
    {__windowSize__.x / 2, __windowSize__.y / 2});
}

static void destroy_credits(minesweeper_t *minesweeper)
{
    mySfText_destroy(minesweeper->credits->credits_text);
    free(minesweeper->credits);
}

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
