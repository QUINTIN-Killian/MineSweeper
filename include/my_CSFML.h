#ifndef MY_CSFML_H_
    #define MY_CSFML_H_
    #define SFNULL ((void *)-1)
    #include <stdbool.h>
    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <string.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include "my_sfColor.h"
    #include "my_sfSize.h"

typedef enum {
    TOP_LEFT,
    TOP_RIGHT,
    BOTTOM_LEFT,
    BOTTOM_RIGHT,
    CENTER_TOP,
    CENTER_BOTTOM,
    CENTER_LEFT,
    CENTER_RIGHT,
    CENTER
} mySfOrigin;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} mySfSprite;

typedef struct {
    sfSoundBuffer *buffer;
    sfSound *sound;
} mySfSound;

typedef struct {
    sfRenderWindow *render_window;
    sfVideoMode mode;
} mySfRenderWindow;

typedef struct {
    sfClock *clock;
    bool pause;
    sfTime buffer;
} mySfClock;

mySfSprite *mySfSprite_create(const char *texturepath, sfBool origin_centered);
void mySfSprite_destroy(mySfSprite *obj);
mySfSound *mySfSound_create(const char *soundpath);
void mySfSound_destroy(mySfSound *obj);
sfText *mySfText_create(const sfFont *font, const char *string, sfColor color,
    sfSize size);
void mySfText_destroy(sfText *obj);
sfMusic *mySfMusic_create(const char *musicpath, sfBool loop, sfBool play);
void mySfMusic_destroy(sfMusic *obj);
sfBool mySfButtonText_isNormal(mySfRenderWindow *window_infos, sfText *text);
sfBool mySfButtonText_isHoover(mySfRenderWindow *window_infos, sfText *text);
sfBool mySfButtonText_isLeftClick(mySfRenderWindow *window_infos, sfText *text,
    sfEvent *event);
void mySfButtonText_setStyle(sfText *text, sfColor color, sfSize size);
void mySfText_setOrigin(sfText *obj, mySfOrigin pos);
sfBool mySfButtonRectangle_isNormal(mySfRenderWindow *window_infos,
    sfRectangleShape *rectangle);
sfBool mySfButtonRectangle_isHoover(mySfRenderWindow *window_infos,
    sfRectangleShape *rectangle);
sfBool mySfButtonRectangle_isLeftClick(mySfRenderWindow *window_infos,
    sfRectangleShape *rectangle, sfEvent *event);
sfBool mySfButtonRectangle_isRightClick(mySfRenderWindow *window_infos,
    sfRectangleShape *rectangle, sfEvent *event);
mySfClock *mySfClock_create(void);
void mySfClock_pause(mySfClock *obj);
void mySfClock_unpause(mySfClock *obj);
sfTime mySfClock_getElapsedTime(mySfClock *obj);
void mySfClock_destroy(mySfClock *obj);

#endif
