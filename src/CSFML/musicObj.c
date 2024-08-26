#include "../../include/my_CSFML.h"

sfMusic *mySfMusicCreate(const char *musicpath, sfBool loop, sfBool play)
{
    sfMusic *obj = sfMusic_createFromFile(musicpath);

    sfMusic_setLoop(obj, loop);
    if (play)
        sfMusic_play(obj);
    return obj;
}

void mySfMusicDestroy(sfMusic *obj)
{
    sfMusic_stop(obj);
    sfMusic_destroy(obj);
}
