#include "my_CSFML.h"

sfText *mySfText_create(const sfFont *font, const char *string, sfColor color,
    SfSize size)
{
    sfText *obj = sfText_create();
    sfFloatRect bounds;

    sfText_setFont(obj, font);
    sfText_setString(obj, string);
    sfText_setFillColor(obj, color);
    if (size != NONE) {
        sfText_setOutlineColor(obj, sfBlack);
        sfText_setOutlineThickness(obj, size / 10);
        sfText_setCharacterSize(obj, size);
    }
    bounds = sfText_getGlobalBounds(obj);
    sfText_setOrigin(obj, (sfVector2f){bounds.width / 2, bounds.height / 2});
    return obj;
}

void mySfText_setOrigin(sfText *obj, originPos pos)
{
    sfFloatRect bounds = sfText_getLocalBounds(obj);

    switch (pos) {
        case CENTER:
            sfText_setOrigin(obj, (sfVector2f){bounds.width / 2.0, bounds.height / 2.0});
            break;
        case TOP_LEFT:
            sfText_setOrigin(obj, (sfVector2f){0.0, 0.0});
            break;
        case TOP_RIGHT:
            sfText_setOrigin(obj, (sfVector2f){bounds.width, 0.0});
            break;
        case BOTTOM_LEFT:
            sfText_setOrigin(obj, (sfVector2f){0.0, bounds.height});
            break;
        case BOTTOM_RIGHT:
            sfText_setOrigin(obj, (sfVector2f){bounds.width, bounds.height});
            break;
        case CENTER_TOP:
            sfText_setOrigin(obj, (sfVector2f){bounds.width / 2.0, 0.0});
            break;
        case CENTER_BOTTOM:
            sfText_setOrigin(obj, (sfVector2f){bounds.width / 2.0, bounds.height});
            break;
        case CENTER_LEFT:
            sfText_setOrigin(obj, (sfVector2f){0.0, bounds.height / 2.0});
            break;
        case CENTER_RIGHT:
            sfText_setOrigin(obj, (sfVector2f){bounds.width, bounds.height / 2.0});
            break;
        default:
            break;
    }
}

void mySfText_destroy(sfText *obj)
{
    sfText_destroy(obj);
}
