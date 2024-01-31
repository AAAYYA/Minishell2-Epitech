/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** my_strdup
*/

#include "includes/mysh.h"

char *my_strdup(char const *src)
{
    char *dest = malloc(my_strlen(src) * sizeof(char) + 1);
    my_strcpy(dest, src);
    return dest;
}

int my_min(int n1, int n2)
{
    if (n1 < n2)
        return n1;
    return n2;
}

char *my_strndup(char const *src, int n)
{
    char *dest = malloc(my_min(my_strlen(src), n) * sizeof(char) + 1);
    my_strncpy(dest, src, n);
    return dest;
}

void my_show_word_array(char **arr)
{
    for (int i = 0; arr[i] != NULL; i++) {
        for (int j = 0; arr[i][j] != '\0'; j++)
            my_putchar(arr[i][j]);
        my_putchar('\n');
    }
}
