/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** find the biggest square
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "includes/mysh.h"

int my_count_char(char const *str, char d)
{
    int b = 0;

    for (int a = 0; str[a] < my_strlen(str); a++)
        if (str[a] == d)
            b++;
    return b;
}

char **second_str_to_word_array(char const *str, char delim, int i[3])
{
    int last_delim = delim_last(str, delim);
    char **tab = alloc(str, delim, last_delim);
    for (; i[2] < last_delim; i[0]++, i[2]++) {
        tab[i[0]] = malloc(sizeof(char) * (word_len(str, delim, i[2]) + 1));
        i[1] = 0;
        for (; str[i[2]] != delim; i[2]++, i[1]++) {
            tab[i[0]][i[1]] = str[i[2]];
        }
        tab[i[0]][i[1]] = '\0';
    }
    return tab;
}

char **my_str_to_word_array(char const *str, char delim)
{
    int i[3];
    i[0] = 0;
    i[1] = 0;
    i[2] = 0;
    int lengh = my_strlen(str);
    int last_delim = delim_last(str, delim);
    char **tab = second_str_to_word_array(str, delim, i);
    if (lengh - 1 == last_delim) {
        tab[i[0]] = NULL;
    } else {
        i[1] = 0;
        tab[i[0]] = malloc(sizeof(char) * (word_len(str, '\0', i[2]) + 1));
        for (; str[i[2]] != '\0'; i[2]++, i[1]++) {
            tab[i[0]][i[1]] = str[i[2]];
        }
        tab[i[0]][i[1]] = '\0';
        tab[i[0] + 1] = NULL;
    }
    return tab;
}
