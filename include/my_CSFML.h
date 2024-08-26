#ifndef MY_CSFML_H_
    #define MY_CSFML_H_
    #define SFNULL ((void*)-1)
    #define sfMusic musicObj
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

sfVector2f __init_vector2fObj__(float x, float y);
sfVector2i __init_vector2iObj__(int x, int y);
sfVector2u __init_vector2uObj__(unsigned int x, unsigned int y);

#endif
