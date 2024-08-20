#include "../include/minesweeper.h"

void init_credits(game_t *game)
{
    sfFloatRect bounds;

    game->credits = malloc(sizeof(credits_t));
    game->credits->credits_text = sfText_create();
    sfText_setFont(game->credits->credits_text, game->window->main_font);
    sfText_setString(game->credits->credits_text,
    "Game created by Killian QUINTIN\n(all rights reserved)");
    bounds = sfText_getGlobalBounds(game->credits->credits_text);
    sfText_setOrigin(game->credits->credits_text,
    (sfVector2f){bounds.width / 2, bounds.height / 2});
    sfText_setPosition(game->credits->credits_text, (sfVector2f)
    {game->window->window_size.x / 2, game->window->window_size.y / 2});
    sfText_setColor(game->credits->credits_text, (sfColor){255, 255, 255, 0});
}

void destroy_credits(game_t *game)
{
    sfText_destroy(game->credits->credits_text);
    free(game->credits);
}

void credits(game_t *game)
{
    init_credits(game);
    while (sfRenderWindow_isOpen(game->window->infos) &&
    sfText_getColor(game->credits->credits_text).a < 255) {
        sfRenderWindow_clear(game->window->infos, sfBlack);
        get_event(game, 3, &close_window_event,
        &mute_musics_event, &manage_musics_event);
        sfRenderWindow_drawText(game->window->infos,
        game->credits->credits_text, NULL);
        sfRenderWindow_display(game->window->infos);
        sfText_setColor(game->credits->credits_text,(sfColor){255, 255, 255,
        sfText_getColor(game->credits->credits_text).a + 1});
    }
    while (sfRenderWindow_isOpen(game->window->infos) &&
    sfText_getColor(game->credits->credits_text).a > 0) {
        sfRenderWindow_clear(game->window->infos, sfBlack);
        get_event(game, 3, &close_window_event,
        &mute_musics_event, &manage_musics_event);
        sfRenderWindow_drawText(game->window->infos,
        game->credits->credits_text, NULL);
        sfRenderWindow_display(game->window->infos);
        sfText_setColor(game->credits->credits_text,(sfColor){255, 255, 255,
        sfText_getColor(game->credits->credits_text).a - 1});
    }
    destroy_credits(game);
    start_screen(game);
}

