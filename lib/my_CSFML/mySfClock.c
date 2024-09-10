#include "my_CSFML.h"

mySfClock *mySfClock_create(void)
{
    mySfClock *obj = malloc(sizeof(mySfClock));

    obj->buffer.microseconds = 0;
    obj->pause = false;
    obj->clock = sfClock_create();
    return obj;
}

void mySfClock_pause(mySfClock *obj)
{
    sfTime elapsed_time = sfClock_getElapsedTime(obj->clock);

    obj->buffer.microseconds = elapsed_time.microseconds -
    obj->buffer.microseconds;
    obj->pause = true;
}

void mySfClock_unpause(mySfClock *obj)
{
    sfTime elapsed_time = sfClock_getElapsedTime(obj->clock);

    obj->buffer.microseconds = elapsed_time.microseconds -
    obj->buffer.microseconds;
    obj->pause = false;
}

sfTime mySfClock_getElapsedTime(mySfClock *obj)
{
    sfTime elapsed_time;

    if (obj->pause)
        return obj->buffer;
    elapsed_time = sfClock_getElapsedTime(obj->clock);
    elapsed_time.microseconds -= obj->buffer.microseconds;
    return elapsed_time;
}

void mySfClock_destroy(mySfClock *obj)
{
    sfClock_destroy(obj->clock);
    free(obj);
}
