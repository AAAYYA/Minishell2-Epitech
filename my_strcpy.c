/*
** EPITECH PROJECT, 2022
** my_strcpy
** File description:
** Copies string to another
*/

#include "includes/mysh.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (src[i] != '\0' && i < n) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char *frees(size_t size)
{
    char *str = malloc(sizeof(char) * size + 1);
    for (int i = 0; i < size + 1; i++) {
        str[i] = '\0';
    }
    return str;
}
