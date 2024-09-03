#ifndef MINESWEEPER_H_
    #define MINESWEEPER_H_
    #define __windowSize__ minesweeper->window->window_size
    #define __renderWindow__ minesweeper->window->render_window
    #define __videoMode__ minesweeper->window->mode
    #define __windowInfos__ minesweeper->window->window_infos
    #define __mainFont__ minesweeper->window->main_font
    #include "my.h"
    #include "my_CSFML.h"
    #include <stdbool.h>
    #include <time.h>

typedef struct window_s {
    sfFont *main_font;
    sfRenderWindow *render_window;
    sfVideoMode mode;
    renderWindowObj window_infos;
    sfVector2u window_size;
    spriteObj *background;
} window_t;

typedef struct credits_s {
    sfText *credits_text;
} credits_t;

typedef struct sounds_s {
    soundObj *mining_sound;
    soundObj *breaking_sound;
    soundObj *flag_sound;
} sounds_t;

typedef struct musics_s {
    sfMusic *main_music;
} musics_t;

typedef enum digState_s {
    DEFAULT,
    DIG,
    END
} digState_t;

typedef enum boxState_s {
    HIDDEN,
    REVEALED,
    FLAGED
} boxState_t;

typedef enum boxType_s {
    VOID,
    NUM1,
    NUM2,
    NUM3,
    NUM4,
    NUM5,
    NUM6,
    NUM7,
    NUM8,
    BOMB,
    FLAG
} boxType_t;

typedef struct box_s {
    boxState_t state;
    boxType_t type;
    spriteObj *flagSprite;
    sfText *textValue;
    sfRectangleShape *rock;
} box_t;

typedef struct start_s {
    sfText *minesweeper_name;
    sfText *start;
    sfText *leave;
    bool start_minesweeper;
} start_t;

typedef struct game_s {
    box_t **grid;
    sfText *timer;
    sfClock *clock;
    sfVector2f default_box_size;
} game_t;

typedef struct minesweeper_s {
    int **map;
    int width;
    int height;
    int total_bombs;
    int bombs_left;
    window_t *window;
    sounds_t *sounds;
    musics_t *musics;
    credits_t *credits;
    start_t *start;
    game_t *game;
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
void draw_start(minesweeper_t *minesweeper);
void get_event(minesweeper_t *minesweeper, int nb_events, ...);
void close_window_event(minesweeper_t *minesweeper, sfEvent *event);
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
box_t *init_box(minesweeper_t *minesweeper, boxState_t state, boxType_t type);
void set_box(box_t *box, sfVector2f position, sfSize size);
void draw_box(minesweeper_t *minesweeper, box_t *box);
void destroy_box(box_t *box);
box_t **generate_grid(minesweeper_t *minesweeper);
void draw_grid(minesweeper_t *minesweeper);
void destroy_grid(minesweeper_t *minesweeper);
void set_grid(minesweeper_t *minesweeper);
void dig_event(minesweeper_t *minesweeper, sfEvent *event);
void reveal_boxes(minesweeper_t *minesweeper, int x, int y);

#endif
