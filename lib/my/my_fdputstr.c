/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** write one by one the characters of a string in a file
** my_fdputstr
*/

#include "my.h"

int my_fdputstr(int fd, char const *str)
{
    int ind = 0;

    while (str[ind] != '\0') {
        my_fdputchar(fd, str[ind]);
        ind++;
    }
    return 0;
}
