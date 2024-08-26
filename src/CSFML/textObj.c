#include "../../include/my_CSFML.h"

textObj *__init_textObj__(const sfFont *font, const char *string,
    sfVector2f *origin, sfVector2f *position, sfColor *color,
    sfVector2f *scale)
{
    textObj *text = malloc(sizeof(textObj));

    text->text = sfText_create();
    if (font != NULL)
        sfText_setFont(text->text, font);
    if (string != NULL)
        sfText_setString(text->text, string);
    text->bounds = sfText_getGlobalBounds(text->text);
    if (origin == SFNULL)
        sfText_setOrigin(text->text,
        __init_vector2fObj__(text->bounds.width / 2, text->bounds.height / 2));
    else if (origin != NULL)
        sfText_setOrigin(text->text, *origin);
    if (position != NULL)
        sfText_setPosition(text->text, *position);
    if (color != NULL)
        sfText_setFillColor(text->text, sfWhite);
    if (scale != NULL)
        sfText_setScale(text->text, (sfVector2f){1.5, 1.5});
    return text;
}

void __dest_textObj__(textObj *text)
{
    sfText_destroy(text->text);
}
