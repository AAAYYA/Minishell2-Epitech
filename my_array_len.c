/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** my_array_len
*/

#include "includes/mysh.h"

int my_array_len(char **arr)
{
    int i = 0;
    for (i = 0; arr[i] != NULL; i++);
    return i;
}
