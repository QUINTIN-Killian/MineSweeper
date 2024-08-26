#include "../../include/my_CSFML.h"

spriteObj *mySfSpriteCreate(const char *texturepath)
{
    spriteObj *obj = malloc(sizeof(spriteObj));

    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(texturepath, NULL);
    sfSprite_setTexture(obj->sprite, obj->texture, sfFalse);
    return obj;
}

void mySfSpriteDestroy(spriteObj *obj)
{
    sfTexture_destroy(obj->texture);
    sfSprite_destroy(obj->sprite);
}
