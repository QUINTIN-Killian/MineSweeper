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
    #define BOX_SCALE 0.04f

typedef struct window_s {
    sfFont *main_font;
    sfRenderWindow *render_window;
    sfVideoMode mode;
    mySfRenderWindow window_infos;
    sfVector2u window_size;
    mySfSprite *background;
} window_t;

typedef struct credits_s {
    sfText *credits_text;
} credits_t;

typedef struct sounds_s {
    mySfSound *mining_sound;
    mySfSound *breaking_sound;
    mySfSound *flag_sound;
    mySfSound *explosion_sound;
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
    mySfSprite *flag;
    mySfSprite *mine;
    sfText *textValue;
    sfRectangleShape *rectangle;
} box_t;

typedef struct start_s {
    sfText *minesweeper_name;
    sfText *start;
    sfText *leave;
    bool start_minesweeper;
} start_t;

typedef struct game_s {
    bool first_play;
    box_t **grid;
    sfText *timer;
    mySfClock *clock;
    sfVector2f default_box_size;
} game_t;

typedef struct pause_s {
    sfRectangleShape *background;
    sfText *pause;
    sfText *resume;
    sfText *restart;
    sfText *leave;
} pause_t;

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
    pause_t *pause;
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
void init_sounds(minesweeper_t *minesweeper);
void destroy_sounds(minesweeper_t *minesweeper);
void init_musics(minesweeper_t *minesweeper);
void destroy_musics(minesweeper_t *minesweeper);
void mute_musics_event(minesweeper_t *minesweeper, sfEvent *event);
void manage_musics_event(minesweeper_t *minesweeper, sfEvent *event);
void credits(minesweeper_t *minesweeper);
void game(minesweeper_t *minesweeper);
void draw(minesweeper_t *minesweeper, int nb_draw, ...);
box_t *init_box(minesweeper_t *minesweeper, boxState_t state, boxType_t type,
    sfVector2f pos);
void draw_box(minesweeper_t *minesweeper, box_t *box);
void destroy_box(box_t *box);
box_t **generate_grid(minesweeper_t *minesweeper);
void draw_grid(minesweeper_t *minesweeper);
void destroy_grid(minesweeper_t *minesweeper);
void dig_event(minesweeper_t *minesweeper, sfEvent *event);
void reveal_box(minesweeper_t *minesweeper, int x, int y);
void reveal_grid(minesweeper_t *minesweeper);
void game_boxEvent(minesweeper_t *minesweeper, sfEvent *event);
void start_startEvent(minesweeper_t *minesweeper, sfEvent *event);
void start_leaveEvent(minesweeper_t *minesweeper, sfEvent *event);
void mine(minesweeper_t *minesweeper, int x, int y);
void flag(minesweeper_t *minesweeper, int x, int y);
void unflag(minesweeper_t *minesweeper, int x, int y);
void init_start(minesweeper_t *minesweeper);
void destroy_start(minesweeper_t *minesweeper);
void init_game(minesweeper_t *minesweeper);
void destroy_game(minesweeper_t *minesweeper);
void draw_timer(minesweeper_t *minesweeper);
void init_credits(minesweeper_t *minesweeper);
void destroy_credits(minesweeper_t *minesweeper);
void set_box(minesweeper_t *minesweeper, box_t *box);
bool is_in_range_grid(int width, int height, int x, int y);
void pause_event(minesweeper_t *minesweeper, sfEvent *event);
void init_pause(minesweeper_t *minesweeper);
void destroy_pause(minesweeper_t *minesweeper);
void draw_pause(minesweeper_t *minesweeper);
void pause_continueEvent(minesweeper_t *minesweeper, sfEvent *event);
void pause_restartEvent(minesweeper_t *minesweeper, sfEvent *event);
void pause_leaveEvent(minesweeper_t *minesweeper, sfEvent *event);

#endif
