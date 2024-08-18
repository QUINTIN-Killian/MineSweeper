/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** writes a character in a file
** my_fdputchar
*/

#include "my.h"

void my_fdputchar(int fd, char c)
{
    if (fd == 2) {
        write(fd, "\e[31m", 5);
        write(fd, &c, 1);
        write(fd, "\e[0m", 4);
        return;
    }
    write(fd, &c, 1);
}
