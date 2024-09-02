#ifndef MY_CSFML_H_
    #define MY_CSFML_H_
    #define SFNULL ((void*)-1)
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
} originPos;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} spriteObj;

typedef struct {
    sfSoundBuffer *buffer;
    sfSound *sound;
} soundObj;

typedef struct {
    sfRenderWindow *render_window;
    sfVideoMode infos;
} renderWindowObj;

spriteObj *mySfSprite_create(const char *texturepath, sfBool origin_centered);
void mySfSprite_destroy(spriteObj *obj);
soundObj *mySfSound_create(const char *soundpath);
void mySfSound_destroy(soundObj *obj);
sfText *mySfText_create(const sfFont *font, const char *string, sfColor color,
    sfSize size);
void mySfText_destroy(sfText *obj);
sfMusic *mySfMusic_create(const char *musicpath, sfBool loop, sfBool play);
void mySfMusic_destroy(sfMusic *obj);
sfBool mySfButtonSprite_isNormal(renderWindowObj *render_window,
    spriteObj *sprite);
sfBool mySfButtonSprite_isHoover(renderWindowObj *render_window,
    spriteObj *sprite);
sfBool mySfButtonSprite_isLeftClick(renderWindowObj *render_window, spriteObj *sprite,
    sfEvent *event);
sfBool mySfButtonSprite_isRightClick(renderWindowObj *render_window,
    spriteObj *sprite, sfEvent *event);
sfBool mySfButtonText_isNormal(renderWindowObj *render_window, sfText *text);
sfBool mySfButtonText_isHoover(renderWindowObj *render_window, sfText *text);
sfBool mySfButtonText_isLeftClick(renderWindowObj *render_window, sfText *text,
    sfEvent *event);
void mySfText_setOrigin(sfText *obj, originPos pos);

#endif
