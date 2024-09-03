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
    box->mine = NULL;
    if (type == BOMB)
        box->mine = mySfSprite_create("images/Mine.png", sfFalse);
    box->flag = mySfSprite_create("images/Flag.png", sfFalse);
    box->rock = sfRectangleShape_create();
    sfRectangleShape_setOutlineColor(box->rock, sfBlack);
    sfRectangleShape_setOutlineThickness(box->rock, 25.0);
    sfRectangleShape_setFillColor(box->rock, sfGrey);
    sfRectangleShape_setSize(box->rock, minesweeper->game->default_box_size);
    if (type >= NUM1 && type <= NUM8) {
        value = convert_int_to_str(type);
        box->textValue = mySfText_create(__mainFont__, value,
        getColorNb(type), 15.0);
        free(value);
        mySfText_setOrigin(box->textValue, TOP_LEFT);
        sfText_setOrigin(box->textValue, (sfVector2f){-3.0, -3.0});
        return box;
    }
    box->textValue = NULL;
    return box;
}

void set_box(box_t *box, sfVector2f position, sfSize size)
{
    sfRectangleShape_setScale(box->rock, (sfVector2f){size / 30, size / 30});
    sfRectangleShape_setPosition(box->rock,
    (sfVector2f){position.x, position.y});
    sfSprite_setScale(box->flag->sprite,
    (sfVector2f){size / 30, size / 30});
    sfSprite_setPosition(box->flag->sprite, position);
    if (box->textValue != NULL)
        sfText_setPosition(box->textValue, position);
    if (box->mine != NULL) {
        sfSprite_setScale(box->mine->sprite,
        (sfVector2f){size / 10, size / 10});
        sfSprite_setPosition(box->mine->sprite, position);
    }
}

void draw_box(minesweeper_t *minesweeper, box_t *box)
{
    sfRenderWindow_drawRectangleShape(__renderWindow__, box->rock, NULL);
    if (box->state == REVEALED) {
        if (box->textValue != NULL)
            sfRenderWindow_drawText(__renderWindow__, box->textValue, NULL);
        if (box->mine != NULL)
            sfRenderWindow_drawSprite(__renderWindow__, box->mine->sprite, NULL);
        return;
    }
    if (box->state == FLAGED) {
        sfRenderWindow_drawSprite(__renderWindow__, box->flag->sprite,
        NULL);
        return;
    }
}

static bool is_in_range_grid(int width, int height, int x, int y)
{
    return (y >= 0 && y < height && x >= 0 && x < width);
}

static void reveal_around_boxes(minesweeper_t *minesweeper, int x, int y)
{
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (!is_in_range_grid(minesweeper->width,
            minesweeper->height, j, i))
                continue;
            if (minesweeper->game->grid[i][j].state != REVEALED) {
                minesweeper->game->grid[i][j].state = REVEALED;
                sfRectangleShape_setFillColor(minesweeper->game->
                grid[i][j].rock, sfLightGrey);
            }
        }
    }
}

void reveal_boxes(minesweeper_t *minesweeper, int x, int y)
{
    minesweeper->game->grid[y][x].state = REVEALED;
    sfRectangleShape_setFillColor(minesweeper->game->grid[y][x].rock,
    sfLightGrey);
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (!is_in_range_grid(minesweeper->width,
            minesweeper->height, j, i))
                continue;
            if (minesweeper->game->grid[i][j].type == VOID &&
            minesweeper->game->grid[i][j].state != REVEALED)
                reveal_boxes(minesweeper, j, i);
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
    sfRectangleShape_destroy(box->rock);
    mySfSprite_destroy(box->flag);
}
