/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** my_strcat
*/

#include "includes/mysh.h"

char *my_strcat(char *dest, char const *src)
{
    int a = 0;
    int b = my_strlen(dest);
    while (src[a] != '\0') {
        dest[a + b] = src[a];
        a++;
    }
    dest[a + b] = '\0';
    return dest;
}
