/*
** EPITECH PROJECT, 2023
** Untitled (Workspace)
** File description:
** parse a string
** parse_str
*/

#include "my.h"

char *parse_str(char const *str, int ind_start, int ind_end)
{
    char *ans;
    int len = ind_end - ind_start;
    int ind = 0;

    if (str == NULL || ind_end < 0 || ind_start < 0 || len <= 0
    || ind_end > my_strlen(str))
        return NULL;
    ans = malloc(sizeof(char) * (len + 1));
    for (int i = ind_start; i < ind_end; i++) {
        ans[ind] = str[i];
        ind++;
    }
    ans[len] = '\0';
    return ans;
}
