#include "../../include/my_CSFML.h"

musicObj *__init_musicObj__(const char *filepath, sfBool loop, sfBool play)
{
    musicObj *music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(music, loop);
    if (play)
        sfMusic_play(music);
    return music;
}
