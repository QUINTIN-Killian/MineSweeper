/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** convert int to str
** convert_int_to_str
*/

#include "my.h"

static char *convert_int_to_str_neg(int nbr)
{
    int intlen = my_intlen(nbr);
    char *str = malloc(sizeof(char) * (1 + intlen + 1));
    int n = 1;

    str[intlen + 1] = '\0';
    str[0] = '-';
    for (int i = 1; i < intlen + 1; i++) {
        str[i] = nbr / my_compute_power_rec(10, intlen - n) + 48;
        nbr = nbr - (nbr / my_compute_power_rec(10, intlen - n) *
        my_compute_power_rec(10, intlen - n));
        n++;
    }
    return str;
}

static char *convert_int_to_str_pos(int nbr)
{
    int intlen = my_intlen(nbr);
    char *str = malloc(sizeof(char) * (intlen + 1));
    int n = 1;

    str[intlen] = '\0';
    for (int i = 0; i < intlen; i++) {
        str[i] = nbr / my_compute_power_rec(10, intlen - n) + 48;
        nbr = nbr - (nbr / my_compute_power_rec(10, intlen - n) *
        my_compute_power_rec(10, intlen - n));
        n++;
    }
    return str;
}

char *convert_int_to_str(int nbr)
{
    if (nbr < 0)
        return convert_int_to_str_neg(nbr * (-1));
    else
        return convert_int_to_str_pos(nbr);
    return NULL;
}
