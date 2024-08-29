#include "../include/minesweeper.h"

static sfColor getColorNb(boxType_t type)
{
    switch (type) {
        case NUM1:
            return sfBlue;
        case NUM2:
            return sfGreen;
        case NUM3:
            return sfRed;
        case NUM4:
            return sfPurple;
        case NUM5:
            return sfBrown;
        case NUM6:
            return sfTeal;
        case NUM7:
            return sfBlack;
        case NUM8:
            return sfDarkGrey;
        default:
            return sfWhite;
    }
}

box_t *init_box(minesweeper_t *minesweeper, boxState_t state, boxType_t type)
{
    box_t *box = malloc(sizeof(box_t));
    char *value;

    box->state = state;
    box->type = type;
    box->rockSprite = mySfSprite_create("images/RockBox.png", sfTrue);
    box->flagSprite = mySfSprite_create("images/Flag.png", sfTrue);
    if (type >= 1 && type <= 8) {
        value = convert_int_to_str(type);
        box->textValue = mySfText_create(minesweeper->window->main_font, value,
        getColorNb(type), MEDIUM);
        free(value);
        return box;
    }
    box->textValue = NULL;
    return box;
}

void set_box(box_t *box, sfVector2f position, sfSize size)
{
    sfSprite_setScale(box->rockSprite->sprite, (sfVector2f){size / 30, size / 30});
    sfSprite_setPosition(box->rockSprite->sprite, position);
    sfSprite_setScale(box->flagSprite->sprite, (sfVector2f){size / 30, size / 30});
    sfSprite_setPosition(box->flagSprite->sprite, position);
    if (box->textValue != NULL) {
        //sfText_setScale(box->textValue, (sfVector2f){size / 30, size / 30});
        sfText_setPosition(box->textValue, position);
    }
}

void draw_box(minesweeper_t *minesweeper, box_t *box)
{
    sfRenderWindow_drawSprite(__renderWindow__, box->rockSprite->sprite, NULL);
    if (box->state == REVEALED && box->textValue != NULL) {
        sfRenderWindow_drawText(__renderWindow__, box->textValue, NULL);
        return;
    }
    if (box->state == FLAGED) {
        sfRenderWindow_drawSprite(__renderWindow__, box->flagSprite->sprite, NULL);
        return;
    }
}

void destroy_box(box_t *box)
{
    if (box->textValue != NULL)
        mySfText_destroy(box->textValue);
    mySfSprite_destroy(box->rockSprite);
    mySfSprite_destroy(box->flagSprite);
}
