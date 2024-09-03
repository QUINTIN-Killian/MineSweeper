#include "../include/minesweeper.h"

static void init_game(minesweeper_t *minesweeper)
{
    minesweeper->game = malloc(sizeof(game_t));
    minesweeper->game->default_box_size = (sfVector2f){626, 626};
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

bool victory(minesweeper_t *minesweeper)
{
    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            if (minesweeper->game->grid[i][j].state != REVEALED &&
            minesweeper->game->grid[i][j].type != BOMB)
                return false;
        }
    }
    return true;
}

static void mine(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->breaking_sound->sound);
    if (minesweeper->game->grid[y][x].type == BOMB) {
        sfSound_play(minesweeper->sounds->explosion_sound->sound);
        reveal_grid(minesweeper);
    } else {
        reveal_boxes(minesweeper, x, y);
        if (victory(minesweeper))
            return;
            //save best score in a file here !
    }
}


static void flag(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->flag_sound->sound);
    minesweeper->game->grid[y][x].state = FLAGED;
    minesweeper->bombs_left--;
}

static void unflag(minesweeper_t *minesweeper, int x, int y)
{
    sfSound_play(minesweeper->sounds->flag_sound->sound);
    minesweeper->game->grid[y][x].state = HIDDEN;
    minesweeper->bombs_left++;
}

void game_boxEvent(minesweeper_t *minesweeper, sfEvent *event)
{
    for (int i = 0; i < minesweeper->height; i++) {
        for (int j = 0; j < minesweeper->width; j++) {
            if (mySfButtonRectangle_isLeftClick(&__windowInfos__,
            minesweeper->game->grid[i][j].rectangle, event) &&
            minesweeper->game->grid[i][j].state == HIDDEN)
                return mine(minesweeper, j, i);
            if (mySfButtonRectangle_isRightClick(&__windowInfos__,
            minesweeper->game->grid[i][j].rectangle, event) &&
            minesweeper->game->grid[i][j].state == FLAGED)
                return unflag(minesweeper, j, i);
            if (mySfButtonRectangle_isRightClick(&__windowInfos__,
            minesweeper->game->grid[i][j].rectangle, event) &&
            minesweeper->game->grid[i][j].state == HIDDEN)
                return flag(minesweeper, j, i);
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
