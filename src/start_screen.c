#include "../include/minesweeper.h"

void init_start_screen(game_t *game)
{
    sfFloatRect bounds;

    game->start_screen = malloc(sizeof(start_screen_t));
    game->start_screen->game_name = sfText_create();
    sfText_setFont(game->start_screen->game_name, game->window->main_font);
    sfText_setString(game->start_screen->game_name, "MineSweeper");
    bounds = sfText_getGlobalBounds(game->start_screen->game_name);
    sfText_setOrigin(game->start_screen->game_name,
    (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfText_setPosition(game->start_screen->game_name, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 4});
    sfText_setColor(game->start_screen->game_name, sfWhite);
    sfText_setScale(game->start_screen->game_name, (sfVector2f){1.5, 1.5});
    game->start_screen->start_button_sprite = sfSprite_create();
    game->start_screen->start_button_texture =
    sfTexture_createFromFile("images/rock3.png", NULL);
    sfSprite_setTexture(game->start_screen->start_button_sprite,
    game->start_screen->start_button_texture, sfFalse);
    sfSprite_setOrigin(game->start_screen->start_button_sprite, (sfVector2f)
    {sfTexture_getSize(game->start_screen->start_button_texture).x / 2,
    sfTexture_getSize(game->start_screen->start_button_texture).y / 2});
    sfSprite_setPosition(game->start_screen->start_button_sprite, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    sfSprite_setScale(game->start_screen->start_button_sprite,
    (sfVector2f){0.3, 0.3});
    game->start_screen->start = sfText_create();
    sfText_setFont(game->start_screen->start, game->window->main_font);
    sfText_setString(game->start_screen->start, "Start");
    bounds = sfText_getGlobalBounds(game->start_screen->start);
    sfText_setOrigin(game->start_screen->start,
    (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfText_setPosition(game->start_screen->start, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    sfText_setColor(game->start_screen->start, sfWhite);
    game->start_screen->leave_button_sprite = sfSprite_create();
    game->start_screen->leave_button_texture =
    sfTexture_createFromFile("images/rock3.png", NULL);
    sfSprite_setTexture(game->start_screen->leave_button_sprite,
    game->start_screen->leave_button_texture, sfFalse);
    sfSprite_setOrigin(game->start_screen->leave_button_sprite, (sfVector2f)
    {sfTexture_getSize(game->start_screen->leave_button_texture).x / 2,
    sfTexture_getSize(game->start_screen->leave_button_texture).y / 2});
    sfSprite_setPosition(game->start_screen->leave_button_sprite, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 1.5});
    sfSprite_setScale(game->start_screen->leave_button_sprite,
    (sfVector2f){0.3, 0.3});
    game->start_screen->leave = sfText_create();
    sfText_setFont(game->start_screen->leave, game->window->main_font);
    sfText_setString(game->start_screen->leave, "Leave");
    bounds = sfText_getGlobalBounds(game->start_screen->leave);
    sfText_setOrigin(game->start_screen->leave,
    (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfText_setPosition(game->start_screen->leave, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 1.5});
    sfText_setColor(game->start_screen->leave, sfWhite);
}

void draw_start_screen(game_t *game)
{
    sfRenderWindow_drawText(game->window->infos,
    game->start_screen->game_name, NULL);
    sfRenderWindow_drawSprite(game->window->infos,
    game->start_screen->start_button_sprite, NULL);
    sfRenderWindow_drawText(game->window->infos,
    game->start_screen->start, NULL);
    sfRenderWindow_drawSprite(game->window->infos,
    game->start_screen->leave_button_sprite, NULL);
    sfRenderWindow_drawText(game->window->infos,
    game->start_screen->leave, NULL);
}

void destroy_start_screen(game_t *game)
{
    sfText_destroy(game->start_screen->game_name);
    sfSprite_destroy(game->start_screen->start_button_sprite);
    sfTexture_destroy(game->start_screen->start_button_texture);
    sfText_destroy(game->start_screen->start);
    sfSprite_destroy(game->start_screen->leave_button_sprite);
    sfTexture_destroy(game->start_screen->leave_button_texture);
    sfText_destroy(game->start_screen->leave);
    free(game->start_screen);
}

void start_screen(game_t *game)
{
    init_start_screen(game);
    while (sfRenderWindow_isOpen(game->window->infos)) {
        sfRenderWindow_clear(game->window->infos, sfCyan);
        draw_background(game);
        draw_start_screen(game);
        draw_cursor(game);
        get_event(game, 5, &change_cursor_event, &close_window_event,
        &dig_animation_event, &mute_musics_event, &manage_musics_event);
        dig_animation(game);
        sfRenderWindow_display(game->window->infos);
    }
    destroy_start_screen(game);
}
