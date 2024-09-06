#include "my_CSFML.h"

sfBool mySfButtonText_isNormal(mySfRenderWindow *window_infos, sfText *text)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(window_infos->render_window);
    sfVector2u windowSize =
    sfRenderWindow_getSize(window_infos->render_window);
    sfFloatRect bounds = sfText_getGlobalBounds(text);
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

sfBool mySfButtonText_isHoover(mySfRenderWindow *window_infos, sfText *text)
{
    sfVector2i mousePos =
    sfMouse_getPositionRenderWindow(window_infos->render_window);
    sfVector2u windowSize =
    sfRenderWindow_getSize(window_infos->render_window);
    sfFloatRect bounds = sfText_getGlobalBounds(text);
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

sfBool mySfButtonText_isLeftClick(mySfRenderWindow *window_infos, sfText *text,
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
    mousePos = sfMouse_getPositionRenderWindow(window_infos->render_window);
    windowSize = sfRenderWindow_getSize(window_infos->render_window);
    bounds = sfText_getGlobalBounds(text);
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
