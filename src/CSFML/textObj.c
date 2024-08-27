#include "../../include/my_CSFML.h"

sfText *mySfTextCreate(const sfFont *font, const char *string, sfColor color)
{
    sfText *obj = sfText_create();
    sfFloatRect bounds;

    sfText_setFont(obj, font);
    sfText_setString(obj, string);
    sfText_setFillColor(obj, color);
    bounds = sfText_getGlobalBounds(obj);
    sfText_setOrigin(obj, (sfVector2f){bounds.width / 2, bounds.height / 2});
    return obj;
}

void mySfTextDestroy(sfText *obj)
{
    sfText_destroy(obj);
}
