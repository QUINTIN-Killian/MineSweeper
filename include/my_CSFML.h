#ifndef MY_CSFML_H_
    #define MY_CSFML_H_
    #define SFNULL ((void*)-1)
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
    sfFloatRect bounds;
} spriteObj;

typedef struct {
    sfSoundBuffer *buffer;
    sfSound *sound;
} soundObj;

typedef struct {
    sfText *text;
    sfFloatRect bounds;
} textObj;

sfColor __init_colorObj__(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a);
sfVector2f __init_vector2fObj__(float x, float y);
sfVector2i __init_vector2iObj__(int x, int y);
sfVector2u __init_vector2uObj__(unsigned int x, unsigned int y);
sfMusic *__init_musicObj__(const char *filepath, sfBool loop, sfBool play);
void __dest_musicObj__(sfMusic *music);
soundObj *__init_sfSound__(const char *filepath);
void __dest_sfSound__(soundObj *sound);
spriteObj *__init_spriteObj__(const char *texturepath, sfVector2f *origin,
    sfVector2f *position, float rotation, sfVector2f *scale);
void __dest_spriteObj__(spriteObj *sprite);
textObj *__init_textObj__(const sfFont *font, const char *string, sfVector2f *
    origin, sfVector2f *position, sfColor *color, sfVector2f *scale);
void __dest_textObj__(textObj *text);

#endif
