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

box_t *init_box(minesweeper_t *minesweeper, boxState_t state, boxType_t type,
    sfVector2f pos)
{
    box_t *box = malloc(sizeof(box_t));
    sfVector2u flag_size;

    box->state = state;
    box->type = type;
    box->mine = NULL;
    box->textValue = NULL;
    box->rectangle = sfRectangleShape_create();
    sfRectangleShape_setScale(box->rectangle, (sfVector2f){BOX_SCALE,
    BOX_SCALE});
    sfRectangleShape_setPosition(box->rectangle, pos);
    sfRectangleShape_setOutlineColor(box->rectangle, sfBlack);
    sfRectangleShape_setOutlineThickness(box->rectangle, 25.0);
    sfRectangleShape_setFillColor(box->rectangle, sfGrey);
    sfRectangleShape_setSize(box->rectangle, minesweeper->game->default_box_size);
    box->flag = mySfSprite_create("images/Flag.png", sfFalse);
    flag_size = sfTexture_getSize(box->flag->texture);
    sfSprite_setScale(box->flag->sprite, (sfVector2f){BOX_SCALE, BOX_SCALE});
    sfSprite_setPosition(box->flag->sprite,(sfVector2f){pos.x +
    (minesweeper->game->default_box_size.x * BOX_SCALE - flag_size.x *
    BOX_SCALE) / 2.0, pos.y + (minesweeper->game->default_box_size.y *
    BOX_SCALE - flag_size.y * BOX_SCALE) / 2.0});
    return box;
}

static bool is_in_range_grid(int width, int height, int x, int y)
{
    return (y >= 0 && y < height && x >= 0 && x < width);
}

void set_box(minesweeper_t *minesweeper, box_t *box)
{
    char *value;
    sfVector2f pos = sfRectangleShape_getPosition(box->rectangle);

    box->state = REVEALED;
    sfRectangleShape_setFillColor(box->rectangle, sfLightGrey);
    if (box->type == BOMB) {
        box->mine = mySfSprite_create("images/Mine.png", sfFalse);
        sfSprite_setScale(box->mine->sprite,
        (sfVector2f){BOX_SCALE * 3, BOX_SCALE * 3});
        sfSprite_setPosition(box->mine->sprite, pos);
        return;
    }
    if (box->type >= NUM1 && box->type <= NUM8) {
        value = convert_int_to_str(box->type);
        box->textValue = mySfText_create(__mainFont__, value,
        getColorNb(box->type), 15.0);
        free(value);
        mySfText_setOrigin(box->textValue, TOP_LEFT);
        sfText_setOrigin(box->textValue, (sfVector2f){-3.0, -3.0});
        sfText_setPosition(box->textValue, pos);
        return;
    }
}

static void reveal_around_boxes(minesweeper_t *minesweeper, int x, int y)
{
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (!is_in_range_grid(minesweeper->width,
            minesweeper->height, j, i))
                continue;
            if (minesweeper->game->grid[i][j].state != REVEALED)
                set_box(minesweeper, &minesweeper->game->grid[i][j]);
        }
    }
}

void reveal_box(minesweeper_t *minesweeper, int x, int y)
{
    set_box(minesweeper, &minesweeper->game->grid[y][x]);
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (!is_in_range_grid(minesweeper->width,
            minesweeper->height, j, i))
                continue;
            if (minesweeper->game->grid[i][j].type == VOID &&
            minesweeper->game->grid[i][j].state != REVEALED)
                reveal_box(minesweeper, j, i);
        }
    }
    if (minesweeper->game->grid[y][x].type == VOID)
        reveal_around_boxes(minesweeper, x, y);
}

void destroy_box(box_t *box)
{
    if (box->textValue != NULL)
        mySfText_destroy(box->textValue);
    if (box->mine != NULL)
        mySfSprite_destroy(box->mine);
    sfRectangleShape_destroy(box->rectangle);
    if (box->flag != NULL)
        mySfSprite_destroy(box->flag);
}
