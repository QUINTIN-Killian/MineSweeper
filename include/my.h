/*
** EPITECH PROJECT, 2023
** undefined
** File description:
** header of the functions from the library libmy
** functions
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdio.h>
    #include <unistd.h>
    #include <stdlib.h>
    #include <string.h>
    #include <stdarg.h>

void my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_compute_power_rec(int nb, int power);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
int my_str_isnum(char const *str);
char *my_strdup(char const *src);
int my_strlen_array(char **array);
int my_intlen(int n);
int convert_str_in_int(char *str);
char *concat_2_str(char *str1, char *str2);
char *my_strndup(char const *src, int n);
char *convert_int_to_str(int nbr);
int mini_printf(const char *format, ...);
void free_word_array(char **word_array);
char *concat_str(int nb_elt, ...);
char *parse_str(char const *str, int ind_start, int ind_end);
char **my_tabdup(char **tab);
char **sep_str(char const *str, int nb_sep, ...);
void my_fdputchar(int fd, char c);
int my_fdputstr(int fd, char const *str);
int my_fdput_nbr(int fd, int nb);
int mini_fdprintf(int fd, const char *format, ...);
void print_word_array(char **word_array);
int my_abs(int nbr);
char *my_strncpy(char *dest, char const *src, int n);

#endif
