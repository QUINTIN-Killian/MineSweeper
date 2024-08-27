#include "my_CSFML.h"

soundObj *mySfSoundCreate(const char *soundpath)
{
    soundObj *sound = malloc(sizeof(soundObj));

    sound->buffer = sfSoundBuffer_createFromFile(soundpath);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return sound;
}

void mySfSoundDestroy(soundObj *obj)
{
    sfSoundBuffer_destroy(obj->buffer);
    sfSound_destroy(obj->sound);
    free(obj);
}
