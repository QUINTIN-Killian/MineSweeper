/*
** EPITECH PROJECT, 2024
** mini_shell2
** File description:
** duplicate a char **
** my_tabdup
*/

#include "my.h"

char **my_tabdup(char **tab)
{
    char **ans;

    if (tab == NULL)
        return NULL;
    ans = malloc(sizeof(char *) * (my_strlen_array(tab) + 1));
    for (int i = 0; i < my_strlen_array(tab); i++)
        ans[i] = my_strdup(tab[i]);
    ans[my_strlen_array(tab)] = NULL;
    return ans;
}
