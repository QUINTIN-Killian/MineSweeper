#include "../../include/my_CSFML.h"

sfColor __init_colorObj__(sfUint8 r, sfUint8 g, sfUint8 b, sfUint8 a)
{
    sfColor color;

    color.r = r;
    color.g = g;
    color.b = b;
    color.a = a;
    return color;
}
