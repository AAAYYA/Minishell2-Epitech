/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** env
*/

#include "includes/mysh.h"

void delete_elem(char **comm, unsigned int i)
{
    free(comm[i]);
    for (; comm[i] != NULL; i++) {
        comm[i] = comm[i + 1];
    }
    comm[i] = NULL;
}

void delete_empty(char **comm)
{
    int i = 0;

    for (i = 0; comm[i] != NULL; i++) {
        if (comm[i][0] == '\0') {
            delete_elem(comm, i);
            i--;
        }
    }
}

int my_env(minish_t *msh)
{
    int i = 0;
    for (i = 0; msh->envc[i] != NULL; i++) {
        my_putstr(msh->envc[i]);
        my_putchar('\n');
    }
    return 0;
}
