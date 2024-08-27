#ifndef MINESWEEPER_H_
    #define MINESWEEPER_H_
    #define __windowSize__ game->window->window_size
    #define __renderWindow__ game->window->infos
    #include "my.h"
    #include "my_CSFML.h"
    #include <stdbool.h>
    #include <time.h>

typedef struct window_s {
    sfFont *main_font;
    sfVideoMode mode;
    sfRenderWindow *infos;
    sfVector2u window_size;
    char *window_name;
    spriteObj *background;
} window_t;

typedef struct credits_s {
    sfText *credits_text;
} credits_t;

typedef struct sounds_s {
    soundObj *mining_sound;
    soundObj *breaking_sound;
} sounds_t;

typedef struct musics_s {
    sfMusic *main_music;
} musics_t;

typedef struct start_screen_s {
    sfText *game_name;
    spriteObj *start_button;
    sfText *start;
    spriteObj *leave_button;
    sfText *leave;
    bool start_game;
} start_screen_t;

typedef enum dig_state_s {
    DEFAULT,
    DIG,
    END
} dig_state_t;

typedef struct cursor_s {
    bool pickaxe_cursor;
    dig_state_t state;
    spriteObj *cursor;
} cursor_t;

typedef enum box_state_s {
    HIDDEN,
    REVEALED,
    FLAGED
} box_state_t;

typedef struct box_s {
    box_state_t state;
    sfSprite *box_sprite;
    sfTexture *box_texture;
    sfVector2f coords;
    sfFloatRect box_bounds;
    struct box_s *next;
} box_t;

typedef struct game_s {
    int **map;
    int width;
    int height;
    int total_bombs;
    int bombs_left;
    window_t *window;
    box_t **boxes;
    cursor_t *cursor;
    sounds_t *sounds;
    musics_t *musics;
    credits_t *credits;
    start_screen_t *start_screen;
} game_t;

int randint(int a, int b);
void create_map(game_t *game);
void print_map(game_t *game);
void destroy_map(game_t *game);
void place_bombs(game_t *game);
void set_map_values(game_t *game);
void init_window(game_t *game);
void draw_background(game_t *game);
void destroy_window(game_t *game);
void start_screen(game_t *game);
void init_cursor(game_t *game);
void draw_cursor(game_t *game);
void destroy_cursor(game_t *game);
void get_event(game_t *game, int nb_events, ...);
void close_window_event(game_t *game, sfEvent *event);
void change_cursor_event(game_t *game, sfEvent *event);
void dig_animation_event(game_t *game, sfEvent *event);
void dig_animation(game_t *game);
void debug(void);
void init_sounds(game_t *game);
void destroy_sounds(game_t *game);
void init_musics(game_t *game);
void destroy_musics(game_t *game);
void mute_musics_event(game_t *game, sfEvent *event);
void manage_musics_event(game_t *game, sfEvent *event);
void credits(game_t *game);
void start_menu_start_game_event(game_t *game, sfEvent *event);
void start_menu_leave_game_event(game_t *game, sfEvent *event);
void game_screen(game_t *game);

#endif
