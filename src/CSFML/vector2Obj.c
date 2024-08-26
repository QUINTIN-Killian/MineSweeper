#include "../../include/my_CSFML.h"

sfVector2f __init_vector2fObj__(float x, float y)
{
    sfVector2f coords;

    coords.x = x;
    coords.y = y;
    return coords;
}

sfVector2i __init_vector2iObj__(int x, int y)
{
    sfVector2i coords;

    coords.x = x;
    coords.y = y;
    return coords;
}

sfVector2u __init_vector2uObj__(unsigned int x, unsigned int y)
{
    sfVector2u coords;

    coords.x = x;
    coords.y = y;
    return coords;
}
