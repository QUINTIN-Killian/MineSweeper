#include "my_CSFML.h"

mySfSound *mySfSound_create(const char *soundpath)
{
    mySfSound *sound = malloc(sizeof(mySfSound));

    sound->buffer = sfSoundBuffer_createFromFile(soundpath);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return sound;
}

void mySfSound_destroy(mySfSound *obj)
{
    sfSoundBuffer_destroy(obj->buffer);
    sfSound_destroy(obj->sound);
    free(obj);
}
