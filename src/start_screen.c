#include "../include/minesweeper.h"

void init_start_screen(game_t *game)
{
    game->start_screen = malloc(sizeof(start_screen_t));
    game->start_screen->game_name = mySfTextCreate(game->window->main_font,
    "MineSweeper", sfWhite);
    sfText_setPosition(game->start_screen->game_name, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 4});
    sfText_setScale(game->start_screen->game_name, (sfVector2f){1.5, 1.5});
    game->start_screen->start_button = mySfSpriteCreate("images/rock3.png");
    sfSprite_setPosition(game->start_screen->start_button->sprite, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    sfSprite_setScale(game->start_screen->start_button->sprite,
    (sfVector2f){0.3, 0.3});
    game->start_screen->start = mySfTextCreate(game->window->main_font,
    "Start", sfWhite);
    sfText_setPosition(game->start_screen->start, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    game->start_screen->leave_button = mySfSpriteCreate("images/rock3.png");
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
        &start_menu_start_game_event, &start_menu_leave_game_event);
        dig_animation(game);
        sfRenderWindow_display(game->window->infos);
    }
    destroy_start_screen(game);
    game_screen(game);
}
