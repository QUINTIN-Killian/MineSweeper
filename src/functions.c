#include "../include/minesweeper.h"

int randint(int a, int b)
{
    int abs;

    if (a > b)
        return -1;
    abs = my_abs(a);
    if (a >= 0)
        return rand() % (b - abs + 1) + abs;
    return rand() % (b + abs + 1) - abs;
}
