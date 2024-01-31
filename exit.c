/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** exit
*/

#include "includes/mysh.h"

int exit_msh(minish_t *msh)
{
    exit(msh->status);
}
