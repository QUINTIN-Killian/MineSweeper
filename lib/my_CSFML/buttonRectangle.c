#include "my_CSFML.h"

sfBool mySfButtonRectangle_isNormal(renderWindowObj *window_infos,
    sfRectangleShape *rectangle)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(window_infos->render_window);
    sfVector2u windowSize =
    sfRenderWindow_getSize(window_infos->render_window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rectangle);
    float scaleX = (float)windowSize.x / window_infos->mode.width;
    float scaleY = (float)windowSize.y / window_infos->mode.height;

    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (!(mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height))
        return sfTrue;
    return sfFalse;
}

sfBool mySfButtonRectangle_isHoover(renderWindowObj *window_infos,
    sfRectangleShape *rectangle)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(window_infos->render_window);
    sfVector2u windowSize =
    sfRenderWindow_getSize(window_infos->render_window);
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rectangle);
    float scaleX = (float)windowSize.x / window_infos->mode.width;
    float scaleY = (float)windowSize.y / window_infos->mode.height;

    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height)
        return sfTrue;
    return sfFalse;
}

sfBool mySfButtonRectangle_isLeftClick(renderWindowObj *window_infos,
    sfRectangleShape *rectangle, sfEvent *event)
{
    sfVector2i mousePos;
    sfVector2u windowSize;
    sfFloatRect bounds;
    float scaleX;
    float scaleY;

    if (!(event->type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseLeft)))
        return sfFalse;
    mousePos = sfMouse_getPositionRenderWindow(window_infos->render_window);
    windowSize = sfRenderWindow_getSize(window_infos->render_window);
    bounds = sfRectangleShape_getGlobalBounds(rectangle);
    scaleX = (float)windowSize.x / window_infos->mode.width;
    scaleY = (float)windowSize.y / window_infos->mode.height;
    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height)
        return sfTrue;
    return sfFalse;
}

sfBool mySfButtonRectangle_isRightClick(renderWindowObj *window_infos,
    sfRectangleShape *rectangle, sfEvent *event)
{
    sfVector2i mousePos;
    sfVector2u windowSize;
    sfFloatRect bounds;
    float scaleX;
    float scaleY;

    if (!(event->type == sfEvtMouseButtonPressed &&
    sfMouse_isButtonPressed(sfMouseRight)))
        return sfFalse;
    mousePos = sfMouse_getPositionRenderWindow(window_infos->render_window);
    windowSize = sfRenderWindow_getSize(window_infos->render_window);
    bounds = sfRectangleShape_getGlobalBounds(rectangle);
    scaleX = (float)windowSize.x / window_infos->mode.width;
    scaleY = (float)windowSize.y / window_infos->mode.height;
    bounds.left *= scaleX;
    bounds.top *= scaleY;
    bounds.width *= scaleX;
    bounds.height *= scaleY;
    if (mousePos.x >= bounds.left && mousePos.x <= bounds.left + bounds.width
    && mousePos.y >= bounds.top && mousePos.y <= bounds.top + bounds.height)
        return sfTrue;
    return sfFalse;
}
