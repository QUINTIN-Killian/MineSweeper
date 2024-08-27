#ifndef MY_CSFML_H_
    #define MY_CSFML_H_
    #define SFNULL ((void*)-1)
    #include <stdlib.h>
    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Clock.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
} spriteObj;

typedef struct {
    sfSoundBuffer *buffer;
    sfSound *sound;
} soundObj;

spriteObj *mySfSpriteCreate(const char *texturepath);
void mySfSpriteDestroy(spriteObj *obj);
soundObj *mySfSoundCreate(const char *soundpath);
void mySfSoundDestroy(soundObj *obj);
sfText *mySfTextCreate(const sfFont *font, const char *string, sfColor color);
void mySfTextDestroy(sfText *obj);
sfMusic *mySfMusicCreate(const char *musicpath, sfBool loop, sfBool play);
void mySfMusicDestroy(sfMusic *obj);

#endif
