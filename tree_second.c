/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** tree_second
*/

#include "includes/mysh.h"
#include "includes/ll.h"

char **separate(char **arr, int start, int end)
{
    char **sec_arr = (char **)malloc(sizeof(char *) * (end - start + 2));
    int pos = 0;

    if (sec_arr == NULL)
        return NULL;
    for (int i = start; i <= end; i++) {
        sec_arr[pos] = arr[i];
        pos++;
    }
    sec_arr[pos] = NULL;
    return sec_arr;
}

int recup_elem(char *str)
{
    if (str == NULL)
        return NONE;
    if (!my_strcmp(str, "|"))
        return PIPE;
    if (!my_strcmp(str, ";"))
        return SEPARATOR;
    if (!my_strcmp(str, ">"))
        return WRITE;
    if (!my_strcmp(str, "<"))
        return READ;
    if (!my_strcmp(str, ">>"))
        return APPEND;
    if (!my_strcmp(str, "<<"))
        return GREP;
    return NONE;
}
