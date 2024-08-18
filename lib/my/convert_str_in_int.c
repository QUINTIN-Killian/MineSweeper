/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** Converts a string into an int.
** convert_str_in_int
*/

#include "my.h"

int convert_str_in_int(char *str)
{
    int ans = 0;
    int elt = 0;
    int end = 0;

    if (str[0] == '-') {
        end = 1;
        if (!my_str_isnum(&(str[1])))
            return -42;
    } else
        if (!my_str_isnum(str))
            return -42;
    for (int i = my_strlen(str) - 1; i >= end; i--) {
        ans = ans + (str[i] - 48) *
        (my_compute_power_rec(10, elt));
        elt++;
    }
    if (str[0] == '-')
        return ans * (-1);
    return ans;
}
