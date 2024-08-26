#include "../../include/my_CSFML.h"

sfText *mySfTextCreate(const sfFont *font, const char *string, sfColor color)
{
    sfText *obj = sfText_create();

    sfText_setFont(obj, font);
    sfText_setString(obj, string);
    sfText_setFillColor(obj, color);
    return obj;
}

void mySfTextDestroy(sfText *obj)
{
    sfText_destroy(obj);
}
