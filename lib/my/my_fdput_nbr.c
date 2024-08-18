/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday03-killian.quintin
** File description:
** write the number given as a parameter in a file
** my_fdput_nbr
*/

#include "my.h"

static void write_negative_end(int fd)
{
    my_fdputchar(fd, '-');
    my_fdputchar(fd, '2');
    my_fdputchar(fd, '1');
    my_fdputchar(fd, '4');
    my_fdputchar(fd, '7');
    my_fdputchar(fd, '4');
    my_fdputchar(fd, '8');
    my_fdputchar(fd, '3');
    my_fdputchar(fd, '6');
    my_fdputchar(fd, '4');
    my_fdputchar(fd, '8');
}

static void write_positive_end(int fd)
{
    my_fdputchar(fd, '2');
    my_fdputchar(fd, '1');
    my_fdputchar(fd, '4');
    my_fdputchar(fd, '7');
    my_fdputchar(fd, '4');
    my_fdputchar(fd, '8');
    my_fdputchar(fd, '3');
    my_fdputchar(fd, '6');
    my_fdputchar(fd, '4');
    my_fdputchar(fd, '7');
}

int my_fdput_nbr(int fd, int nb)
{
    if (nb == -2147483648) {
        write_negative_end(fd);
        return 0;
    }
    if (nb == 2147483647) {
        write_positive_end(fd);
        return 0;
    }
    if (nb < 0) {
        my_fdputchar(fd, '-');
        nb = nb * (-1);
    }
    if (nb < 10)
        my_fdputchar(fd, nb + 48);
    else {
        my_fdput_nbr(fd, nb / 10);
        my_fdput_nbr(fd, nb % 10);
    }
    return 0;
}
