#include "../../include/my_CSFML.h"

spriteObj *__init_spriteObj__(const char *texturepath, sfVector2f *origin,
    sfVector2f *position, float rotation, sfVector2f *scale)
{
    spriteObj *sprite = malloc(sizeof(spriteObj));

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(texturepath, NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    sprite->bounds = sfSprite_getGlobalBounds(sprite->sprite);
    if (origin == SFNULL)
        sfSprite_setOrigin(sprite->sprite, __init_vector2fObj__(
        sfTexture_getSize(sprite->texture).x / 2,
        sfTexture_getSize(sprite->texture).y / 2));
    else if (origin != NULL)
        sfSprite_setOrigin(sprite->sprite, *origin);
    if (position != NULL)
        sfSprite_setPosition(sprite->sprite, *position);
    if (scale != NULL)
        sfSprite_setScale(sprite->sprite, *scale);
}
