#include "my_CSFML.h"

sfMusic *mySfMusic_create(const char *musicpath, sfBool loop, sfBool play)
{
    sfMusic *obj = sfMusic_createFromFile(musicpath);

    sfMusic_setLoop(obj, loop);
    if (play)
        sfMusic_play(obj);
    return obj;
}

void mySfMusic_destroy(sfMusic *obj)
{
    sfMusic_stop(obj);
    sfMusic_destroy(obj);
}
