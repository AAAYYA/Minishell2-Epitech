/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-bsminishell2-damian.gil
** File description:
** setenv_next
*/

#include "includes/mysh.h"

void setenv_short(char **comm, char **env, int i)
{
    if (comm[2] != NULL)
        env[i] = my_strcat(env[i], comm[2]);
}
