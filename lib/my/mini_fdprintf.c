/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** Works the same as printf function handling strings flags
** mini_printf
*/

#include "my.h"

static int is_percent(int fd, char c, int *count)
{
    if (c == '%') {
        my_fdputchar(fd, '%');
        *count = *count + 1;
    }
    return 0;
}

static int is_char(int fd, char c, va_list args, int *count)
{
    if (c == 'c') {
        my_fdputchar(fd, va_arg(args, int));
        *count = *count + 1;
    } else {
        return is_percent(fd, c, count);
    }
    return 0;
}

static int is_str(int fd, char c, va_list args, int *count)
{
    char *str;

    if (c == 's') {
        str = va_arg(args, char *);
        *count = *count + my_strlen(str);
        my_fdputstr(fd, str);
    } else {
        return is_char(fd, c, args, count);
    }
    return 0;
}

static int is_int(int fd, char c, va_list args, int *count)
{
    int nbr;

    if (c == 'd' || c == 'i') {
        nbr = va_arg(args, int);
        my_fdput_nbr(fd, nbr);
        *count = *count + my_intlen(nbr);
    } else {
        return is_str(fd, c, args, count);
    }
    return 0;
}

static int is_right_typo(const char *format)
{
    int ind = 0;

    while (ind < my_strlen(format)) {
        if (format[ind] == '%' && ind == my_strlen(format) - 1) {
            return 84;
        }
        if (format[ind] == '%' && ind < my_strlen(format) - 1 &&
        format[ind + 1] != 'd' && format[ind + 1] != 'i' &&
        format[ind + 1] != 's' && format[ind + 1] != 'c' &&
        format[ind + 1] != '%') {
            return 84;
        }
        if (format[ind] == '%' && ind < my_strlen(format) - 1 &&
        (format[ind + 1] == 'd' || format[ind + 1] == 'i' ||
        format[ind + 1] == 's' || format[ind + 1] == 'c' ||
        format[ind + 1] == '%'))
            ind++;
        ind++;
    }
    return 0;
}

int fderror_exit(const char *format)
{
    if (is_right_typo(format) == 84) {
        write(2, "Error : no correct flag found after percentage\n", 47);
        return 84;
    }
    return 0;
}

int mini_fdprintf(int fd, const char *format, ...)
{
    int count = 0;
    int ind = 0;
    va_list args;

    if (fderror_exit(format) == 84)
        return -1;
    va_start(args, format);
    while (format[ind] != '\0') {
        if (ind < my_strlen(format) - 1 && format[ind] == '%') {
            ind++;
            is_int(fd, format[ind], args, &count);
        } else {
            my_fdputchar(fd, format[ind]);
            count++;
        }
        ind++;
    }
    va_end(args);
    return count;
}
