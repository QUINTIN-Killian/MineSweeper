#include "my_CSFML.h"

mySfSprite *mySfSprite_create(const char *texturepath, sfBool origin_centered)
{
    mySfSprite *obj = malloc(sizeof(mySfSprite));

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(texturepath, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    if (origin_centered)
        sfSprite_setOrigin(obj->sprite, (sfVector2f)
        {sfTexture_getSize(obj->texture).x / 2,
        sfTexture_getSize(obj->texture).y / 2});
    return obj;
}

void mySfSprite_destroy(mySfSprite *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    free(obj);
}
