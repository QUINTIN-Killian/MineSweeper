#ifndef MINESWEEPER_H_
    #define MINESWEEPER_H_
    #define __windowSize__ minesweeper->window->window_size
    #define __renderWindow__ minesweeper->window->infos
    #include "my.h"
    #include "my_CSFML.h"
    #include <stdbool.h>
    #include <time.h>

typedef struct window_s {
    sfFont *main_font;
    sfVideoMode mode;
    sfRenderWindow *infos;
    sfVector2u window_size;
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

typedef struct start_s {
    sfText *minesweeper_name;
    sfText *start;
    sfText *leave;
    bool start_minesweeper;
} start_t;

typedef enum dig_state_s {
    DEFAULT,
    DIG,
    END
} dig_state_t;

typedef struct cursor_s {
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

typedef struct minesweeper_s {
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
    start_t *start;
} minesweeper_t;

int randint(int a, int b);
void create_map(minesweeper_t *minesweeper);
void print_map(minesweeper_t *minesweeper);
void destroy_map(minesweeper_t *minesweeper);
void place_bombs(minesweeper_t *minesweeper);
void set_map_values(minesweeper_t *minesweeper);
void init_window(minesweeper_t *minesweeper);
void draw_background(minesweeper_t *minesweeper);
void destroy_window(minesweeper_t *minesweeper);
void start(minesweeper_t *minesweeper);
void init_cursor(minesweeper_t *minesweeper);
void draw_cursor(minesweeper_t *minesweeper);
void draw_start(minesweeper_t *minesweeper);
void destroy_cursor(minesweeper_t *minesweeper);
void get_event(minesweeper_t *minesweeper, int nb_events, ...);
void close_window_event(minesweeper_t *minesweeper, sfEvent *event);
void dig_animation_event(minesweeper_t *minesweeper, sfEvent *event);
void dig_animation(minesweeper_t *minesweeper);
void debug(void);
void init_sounds(minesweeper_t *minesweeper);
void destroy_sounds(minesweeper_t *minesweeper);
void init_musics(minesweeper_t *minesweeper);
void destroy_musics(minesweeper_t *minesweeper);
void mute_musics_event(minesweeper_t *minesweeper, sfEvent *event);
void manage_musics_event(minesweeper_t *minesweeper, sfEvent *event);
void credits(minesweeper_t *minesweeper);
void game(minesweeper_t *minesweeper);
void draw(minesweeper_t *minesweeper, int nb_draw, ...);

#endif
