#include "../../include/my_CSFML.h"

soundObj *__init_sfSound__(const char *filepath)
{
    soundObj *sound = malloc(sizeof(soundObj));

    sound->buffer = sfSoundBuffer_createFromFile(filepath);
    sound->sound = sfSound_create();
    sfSound_setBuffer(sound->sound, sound->buffer);
    return sound;
}

void __dest_sfSound__(soundObj *sound)
{
    sfSoundBuffer_destroy(sound->buffer);
    sfSound_destroy(sound->sound);
}
