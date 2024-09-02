#include "../include/minesweeper.h"

static void init_game(minesweeper_t *minesweeper)
{
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->grid = generate_grid(minesweeper);
    set_grid(minesweeper);
    minesweeper->game->timer = mySfText_create(__mainFont__,
    NULL, sfLightGrey, SMALL);
    sfText_setPosition(minesweeper->game->timer, (sfVector2f)
    {__windowSize__.x / 100, __windowSize__.y / 100});
    minesweeper->game->clock = sfClock_create();
}

static void destroy_game(minesweeper_t *minesweeper)
{
    destroy_grid(minesweeper);
    sfClock_destroy(minesweeper->game->clock);
    mySfText_destroy(minesweeper->game->timer);
}

static void draw_timer(minesweeper_t *minesweeper)
{
    sfTime time = sfClock_getElapsedTime(minesweeper->game->clock);
    float seconds = sfTime_asSeconds(time);
    char *tmp = convert_int_to_str(seconds);

    sfText_setString(minesweeper->game->timer, tmp);
    sfRenderWindow_drawText(__renderWindow__, minesweeper->game->timer, NULL);
    free(tmp);
}

void game_boxEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    renderWindowObj obj = {__renderWindow__, __videoMode__};

    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            if (mySfButtonSprite_isLeftClick(&obj,
            minesweeper->game->grid[i][j].rockSprite, event)) {
                sfSound_play(minesweeper->sounds->breaking_sound->sound);
                reveal_boxes(minesweeper, j, i);
                return;
            } 
            if (mySfButtonSprite_isRightClick(&obj,
            minesweeper->game->grid[i][j].rockSprite, event) &&
            minesweeper->game->grid[i][j].state == FLAGED) {
                sfSound_play(minesweeper->sounds->flag_sound->sound);
                minesweeper->game->grid[i][j].state = HIDDEN;
                return;
            }
            if (mySfButtonSprite_isRightClick(&obj,
            minesweeper->game->grid[i][j].rockSprite, event) &&
            minesweeper->game->grid[i][j].state == HIDDEN) {
                sfSound_play(minesweeper->sounds->flag_sound->sound);
                minesweeper->game->grid[i][j].state = FLAGED;
                return;
            }
        }
    }
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
