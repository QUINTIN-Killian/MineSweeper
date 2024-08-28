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
    #define sfOrange (sfColor){255, 165, 0, 255}
    #define sfPurple (sfColor){128, 0, 128, 255}
    #define sfPink (sfColor){255, 192, 203, 255}
    #define sfBrown (sfColor){165, 42, 42, 255}
    #define sfGrey (sfColor){128, 128, 128, 255}
    #define sfLightGrey (sfColor){211, 211, 211, 255}
    #define sfDarkGrey (sfColor){64, 64, 64, 255}
    #define sfGold (sfColor){255, 215, 0, 255}
    #define sfSilver (sfColor){192, 192, 192, 255}
    #define sfLime (sfColor){0, 255, 0, 255}
    #define sfTeal (sfColor){0, 128, 128, 255}
    #define sfNavy (sfColor){0, 0, 128, 255}
    #define NONE 0.0f
    #define VERY_BIG 50.0f
    #define BIG 40.0f
    #define MEDIUM 30.0f
    #define SMALL 20.0f
    #define VERY_SMALL 10.0f
    #define sfSize float

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
    sfSize type);
void mySfText_destroy(sfText *obj);
sfMusic *mySfMusic_create(const char *musicpath, sfBool loop, sfBool play);
void mySfMusic_destroy(sfMusic *obj);
sfBool mySfButtonSprite_normal(renderWindowObj *render_window,
    spriteObj *sprite, void (*callback)(spriteObj *));
sfBool mySfButtonSprite_hoover(renderWindowObj *render_window,
    spriteObj *sprite, void (*callback)(spriteObj *));
sfBool mySfButtonSprite_click(renderWindowObj *render_window, spriteObj *sprite,
    sfEvent *event, void (*callback)(spriteObj *));
sfBool mySfButtonText_normal(renderWindowObj *render_window, sfText *text,
    void (*callback)(sfText *));
sfBool mySfButtonText_hoover(renderWindowObj *render_window, sfText *text,
    void (*callback)(sfText *));
sfBool mySfButtonText_click(renderWindowObj *render_window, sfText *text,
    sfEvent *event, void (*callback)(sfText *));
void mySfText_setOrigin(sfText *obj, originPos pos);

#endif
