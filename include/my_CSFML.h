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

typedef enum {
    NONE = 0,
    VERY_BIG = 50,
    BIG = 40,
    MEDIUM = 30,
    SMALL = 20,
    VERY_SMALL = 10
} textType;

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

spriteObj *mySfSpriteCreate(const char *texturepath, sfBool origin_centered);
void mySfSpriteDestroy(spriteObj *obj);
soundObj *mySfSoundCreate(const char *soundpath);
void mySfSoundDestroy(soundObj *obj);
sfText *mySfTextCreate(const sfFont *font, const char *string, sfColor color,
    textType type);
void mySfTextDestroy(sfText *obj);
sfMusic *mySfMusicCreate(const char *musicpath, sfBool loop, sfBool play);
void mySfMusicDestroy(sfMusic *obj);
sfBool mySfButtonSpriteNormal(renderWindowObj *render_window,
    spriteObj *sprite, void (*callback)(spriteObj *));
sfBool mySfButtonSpriteHoover(renderWindowObj *render_window,
    spriteObj *sprite, void (*callback)(spriteObj *));
sfBool mySfButtonSpriteClick(renderWindowObj *render_window, spriteObj *sprite,
    sfEvent *event, void (*callback)(spriteObj *));
sfBool mySfButtonTextNormal(renderWindowObj *render_window, sfText *text,
    void (*callback)(sfText *));
sfBool mySfButtonTextHoover(renderWindowObj *render_window, sfText *text,
    void (*callback)(sfText *));
sfBool mySfButtonTextClick(renderWindowObj *render_window, sfText *text,
    sfEvent *event, void (*callback)(sfText *));
void mySfTextSetOrigin(sfText *obj, originPos pos);

#endif
