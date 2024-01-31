/*
** EPITECH PROJECT, 2022
** my_strmcmp
** File description:
** Compare two strings
*/

#include "includes/mysh.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    for (int a = 0; a < n; a++) {
        if (s1[a] != s2[a])
            return 1;
    }
    return 0;
}

int my_strcmp(char const *s1, char const *s2)
{
    int len1 = my_strlen(s1);
    int len2 = my_strlen(s1);
    int i = 0;
    int j = 0;

    for (; i < len1 && j < len2; i++) {
        if (s1[i] != s2[j])
            return s1[i] - s2[j];
        j++;
    }
    return s1[i] - s2[j];
}
