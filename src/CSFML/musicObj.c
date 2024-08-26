#include "../../include/my_CSFML.h"

sfMusic *__init_musicObj__(const char *filepath, sfBool loop, sfBool play)
{
    sfMusic *music = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(music, loop);
    if (play)
        sfMusic_play(music);
    return music;
}

void __dest_musicObj__(sfMusic *music)
{
    sfMusic_destroy(music);
}
