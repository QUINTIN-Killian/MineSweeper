#include "../include/minesweeper.h"

void init_start_screen(game_t *game)
{
    game->start_screen = malloc(sizeof(start_screen_t));
    game->start_screen->game_name = mySfTextCreate(game->window->main_font,
    "MineSweeper", sfWhite);
    sfText_setPosition(game->start_screen->game_name, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 4});
    sfText_setScale(game->start_screen->game_name, (sfVector2f){1.5, 1.5});
    game->start_screen->start_button = mySfSpriteCreate("images/rock3.png",
    sfTrue);
    sfSprite_setPosition(game->start_screen->start_button->sprite, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    sfSprite_setScale(game->start_screen->start_button->sprite,
    (sfVector2f){0.3, 0.3});
    game->start_screen->start = mySfTextCreate(game->window->main_font,
    "Start", sfWhite);
    sfText_setPosition(game->start_screen->start, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    game->start_screen->leave_button = mySfSpriteCreate("images/rock3.png",
    sfTrue);
    sfSprite_setPosition(game->start_screen->leave_button->sprite, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 1.5});
    sfSprite_setScale(game->start_screen->leave_button->sprite,
    (sfVector2f){0.3, 0.3});
    game->start_screen->leave = mySfTextCreate(game->window->main_font,
    "Leave", sfWhite);
    sfText_setPosition(game->start_screen->leave, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 1.5});
    game->start_screen->start_game = false;
}

void draw_start_screen(game_t *game)
{
    sfRenderWindow_drawText(game->window->infos,
    game->start_screen->game_name, NULL);
    sfRenderWindow_drawSprite(game->window->infos,
    game->start_screen->start_button->sprite, NULL);
    sfRenderWindow_drawText(game->window->infos,
    game->start_screen->start, NULL);
    sfRenderWindow_drawSprite(game->window->infos,
    game->start_screen->leave_button->sprite, NULL);
    sfRenderWindow_drawText(game->window->infos,
    game->start_screen->leave, NULL);
}

void destroy_start_screen(game_t *game)
{
    mySfTextDestroy(game->start_screen->game_name);
    mySfSpriteDestroy(game->start_screen->start_button);
    mySfTextDestroy(game->start_screen->start);
    mySfSpriteDestroy(game->start_screen->leave_button);
    mySfTextDestroy(game->start_screen->leave);
    free(game->start_screen);
}

static void start__normal(sfText *start)
{
    sfText_setFillColor(start, sfWhite);
    sfText_setCharacterSize(start, 30);
}

static void start__hoover(sfText *start)
{
    sfText_setFillColor(start, (sfColor){128, 128, 128, 255});
    sfText_setCharacterSize(start, 50);
}

static void start__click(sfText *start)
{
    sfText_setFillColor(start, (sfColor){110, 110, 110, 255});
    sfText_setCharacterSize(start, 45);
}

void start_screen_event(game_t *game, sfEvent *event)
{
    renderWindowObj obj = {game->window->infos, game->window->mode};

    mySfButtonTextNormal(&obj, game->start_screen->start, &start__normal);
    mySfButtonTextHoover(&obj, game->start_screen->start, &start__hoover);
    if (mySfButtonTextClick(&obj, game->start_screen->start, event,
    &start__click)) {
        sfSound_play(game->sounds->breaking_sound->sound);
        game->start_screen->start_game = true;
    }
}

static void leave__normal(sfText *leave)
{
    sfText_setFillColor(leave, sfWhite);
    sfText_setCharacterSize(leave, 30);
}

static void leave__hoover(sfText *leave)
{
    sfText_setFillColor(leave, (sfColor){128, 128, 128, 255});
    sfText_setCharacterSize(leave, 50);
}

static void leave__click(sfText *leave)
{
    sfText_setFillColor(leave, (sfColor){110, 110, 110, 255});
    sfText_setCharacterSize(leave, 45);
}

void leave_screen_event(game_t *game, sfEvent *event)
{
    renderWindowObj obj = {game->window->infos, game->window->mode};

    mySfButtonTextNormal(&obj, game->start_screen->leave, &leave__normal);
    mySfButtonTextHoover(&obj, game->start_screen->leave, &leave__hoover);
    if (mySfButtonTextClick(&obj, game->start_screen->leave, event,
    &leave__click)) {
        sfSound_play(game->sounds->breaking_sound->sound);
        sfRenderWindow_close(game->window->infos);
    }
}

void start_screen(game_t *game)
{
    init_start_screen(game);
    while (sfRenderWindow_isOpen(game->window->infos) &&
    !game->start_screen->start_game) {
        sfRenderWindow_clear(game->window->infos, sfCyan);
        draw_background(game);
        draw_start_screen(game);
        draw_cursor(game);
        get_event(game, 7, &change_cursor_event, &close_window_event,
        &dig_animation_event, &mute_musics_event, &manage_musics_event,
        &start_screen_event, &leave_screen_event);
        dig_animation(game);
        sfRenderWindow_display(game->window->infos);
    }
    destroy_start_screen(game);
}
