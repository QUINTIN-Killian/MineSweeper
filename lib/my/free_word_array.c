/*
** EPITECH PROJECT, 2024
** robot_factory
** File description:
** free a word array
** free_word_array
*/

#include "my.h"

void free_word_array(char **word_array)
{
    if (word_array != NULL) {
        for (int i = 0; i < my_strlen_array(word_array); i++)
            free(word_array[i]);
        free(word_array);
    }
}
