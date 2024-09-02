#include "my_CSFML.h"

sfBool mySfButtonSprite_isNormal(renderWindowObj *render_window,
    spriteObj *sprite)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(render_window->render_window);
    sfVector2u windowSize =
    sfRenderWindow_getSize(render_window->render_window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite->sprite);
    float scaleX = (float)windowSize.x / render_window->infos.width;
    float scaleY = (float)windowSize.y / render_window->infos.height;

    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (!(mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height))
        return sfTrue;
    return sfFalse;
}

sfBool mySfButtonSprite_isHoover(renderWindowObj *render_window,
    spriteObj *sprite)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(render_window->render_window);
    sfVector2u windowSize =
    sfRenderWindow_getSize(render_window->render_window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(sprite->sprite);
    float scaleX = (float)windowSize.x / render_window->infos.width;
    float scaleY = (float)windowSize.y / render_window->infos.height;

    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height)
        return sfTrue;
    return sfFalse;
}

sfBool mySfButtonSprite_isLeftClick(renderWindowObj *render_window, spriteObj *sprite,
    sfEvent *event)
{
    sfVector2i mousePos;
    sfVector2u windowSize;
    sfFloatRect bounds;
    float scaleX;
    float scaleY;

    if (!(event->type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft)))
        return sfFalse;
    mousePos = sfMouse_getPositionRenderWindow(render_window->render_window);
    windowSize = sfRenderWindow_getSize(render_window->render_window);
    bounds = sfSprite_getGlobalBounds(sprite->sprite);
    scaleX = (float)windowSize.x / render_window->infos.width;
    scaleY = (float)windowSize.y / render_window->infos.height;
    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height)
        return sfTrue;
    return sfFalse;
}

sfBool mySfButtonSprite_isRightClick(renderWindowObj *render_window,
    spriteObj *sprite, sfEvent *event)
{
    sfVector2i mousePos;
    sfVector2u windowSize;
    sfFloatRect bounds;
    float scaleX;
    float scaleY;

    if (!(event->type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseRight)))
        return sfFalse;
    mousePos = sfMouse_getPositionRenderWindow(render_window->render_window);
    windowSize = sfRenderWindow_getSize(render_window->render_window);
    bounds = sfSprite_getGlobalBounds(sprite->sprite);
    scaleX = (float)windowSize.x / render_window->infos.width;
    scaleY = (float)windowSize.y / render_window->infos.height;
    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height)
        return sfTrue;
    return sfFalse;
}
