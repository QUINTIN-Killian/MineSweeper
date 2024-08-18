/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** sep_str
*/

#include "my.h"

static char **create_separator_tab(va_list args, int nb_sep)
{
    char *tmp = NULL;
    char **sep = malloc(sizeof(char *) * (nb_sep + 1));

    for (int i = 0; i < nb_sep; i++) {
        tmp = va_arg(args, char *);
        if (tmp == NULL) {
            sep[i] = my_strdup("");
            continue;
        }
        sep[i] = my_strdup(tmp);
    }
    sep[nb_sep] = NULL;
    return sep;
}

char **insert_elt_in_tab(char **tab, char *elt)
{
    char **tmp = my_tabdup(tab);

    free_word_array(tab);
    tab = malloc(sizeof(char *) * (my_strlen_array(tmp) + 2));
    for (int i = 0; i < my_strlen_array(tmp); i++)
        tab[i] = my_strdup(tmp[i]);
    tab[my_strlen_array(tmp)] = my_strdup(elt);
    tab[my_strlen_array(tmp) + 1] = NULL;
    free_word_array(tmp);
    return tab;
}

static int is_sep2(char const *str, char **sep, int ind, int i)
{
    for (int j = ind; j < ind + my_strlen(sep[i]); j++)
        if (str[j] != sep[i][j - ind])
            return 0;
    return 1;
}

static int is_sep(char const *str, char **sep, int *ind)
{
    if (*ind >= my_strlen(str))
        return 0;
    for (int i = 0; i < my_strlen_array(sep); i++) {
        if (my_strlen(sep[i]) == 0 || *ind + my_strlen(sep[i]) >
        my_strlen(str))
            continue;
        if (is_sep2(str, sep, *ind, i)) {
            *ind += my_strlen(sep[i]);
            return my_strlen(sep[i]);
        }
    }
    return 0;
}

static void move_forward_ind_start(char const *str, char **sep, int *ind_start)
{
    while (*ind_start < my_strlen(str) && is_sep(str, sep, ind_start));
}

static char *get_separated_word2(char const *str, char **sep, int *ind_start,
    int *i)
{
    char *tmp;
    int ans = is_sep(str, sep, i);

    if (ans) {
        tmp = parse_str(str, *ind_start, *i - ans);
        *ind_start = *i;
        while (*i < my_strlen(str) && is_sep(str, sep, i))
            *ind_start = *i;
        return tmp;
    }
    return NULL;
}

char *get_separated_word(char const *str, char **sep, int *ind_start)
{
    char *tmp;

    if (*ind_start >= my_strlen(str))
        return NULL;
    for (int i = *ind_start; i < my_strlen(str); i++) {
        tmp = get_separated_word2(str, sep, ind_start, &i);
        if (tmp != NULL)
            return tmp;
    }
    tmp = parse_str(str, *ind_start, my_strlen(str));
    if (tmp == NULL)
        return NULL;
    *ind_start = my_strlen(str);
    return tmp;
}

char **create_separated_tab(char const *str, char **sep, int ind_start)
{
    char **tab = NULL;
    char *tmp = get_separated_word(str, sep, &ind_start);

    while (tmp != NULL) {
        tab = insert_elt_in_tab(tab, tmp);
        free(tmp);
        tmp = get_separated_word(str, sep, &ind_start);
    }
    free_word_array(sep);
    return tab;
}

char **sep_str(char const *str, int nb_sep, ...)
{
    va_list args;
    char **sep;
    int ind_start = 0;

    if (str == NULL || my_strlen(str) == 0 || nb_sep <= 0)
        return NULL;
    va_start(args, nb_sep);
    sep = create_separator_tab(args, nb_sep);
    va_end(args);
    move_forward_ind_start(str, sep, &ind_start);
    if (ind_start >= my_strlen(str)) {
        free_word_array(sep);
        return NULL;
    }
    return create_separated_tab(str, sep, ind_start);
}
