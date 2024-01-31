/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-sokoban-damian.gil
** File description:
** delimcheck
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "includes/mysh.h"

int word_len(char const *str, char delim, int i)
{
    int j = 0;
    while (str[i] != delim) {
        i++, j++;
    }
    return j;
}

int delim_last(char const *str, char delim)
{
    int index = 0;
    int pos = 0;
    while (str[index] != '\0') {
        if (str[index] == delim)
            pos = index;
        index++;
    }
    return pos;
}

int delim_count(char const *str, char delim)
{
    int compteur = 0;
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == delim)
            compteur++;
    return compteur;
}

char **alloc(char const *str, char delim, int last_delim)
{
    int m_value = delim_count(str, delim);
    m_value += (my_strlen(str) - 1 == last_delim ? 1 : 2);
    char **tab = malloc(sizeof(char *) * m_value);
    return tab;
}
