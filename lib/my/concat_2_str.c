/*
** EPITECH PROJECT, 2024
** mini_shell1
** File description:
** concatenate 2 strings
** concat_2_str
*/

#include "my.h"

char *concat_2_str(char *str1, char *str2)
{
    int ind = 0;
    char *ans;
    int len_total = my_strlen(str1) + my_strlen(str2);

    ans = malloc(sizeof(char) * (len_total + 1));
    for (int i = 0; i < my_strlen(str1); i++) {
        ans[ind] = str1[i];
        ind++;
    }
    for (int i = 0; i < my_strlen(str2); i++) {
        ans[ind] = str2[i];
        ind++;
    }
    ans[len_total] = '\0';
    return ans;
}
