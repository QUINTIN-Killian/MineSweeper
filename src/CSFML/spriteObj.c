#include "../../include/my_CSFML.h"

spriteObj *mySfSpriteCreate(const char *texturepath)
{
    spriteObj *obj = malloc(sizeof(spriteObj));

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(texturepath, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    sfSprite_setOrigin(obj->sprite,(sfVector2f)
    {sfTexture_getSize(obj->texture).x / 2,
    sfTexture_getSize(obj->texture).y / 2});
    return obj;
}

void mySfSpriteDestroy(spriteObj *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
    free(obj);
}
