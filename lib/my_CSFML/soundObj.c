#include "my_CSFML.h"

soundObj *mySfSound_create(const char *soundpath)
{
    soundObj *sound = malloc(sizeof(soundObj));

    sound->buffer = sfSoundBuffer_createFromFile(soundpath);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return sound;
}

void mySfSound_destroy(soundObj *obj)
{
    sfSoundBuffer_destroy(obj->buffer);
    sfSound_destroy(obj->sound);
    free(obj);
}
