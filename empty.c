/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** empty
*/

#include "includes/mysh.h"

int empty_character(minish_t *msh, char **env)
{
    if (msh->command[0] == '\0')
        return 84;
    msh->comm = my_str_to_array(msh->command, ' ', '\t');
    delete_empty(msh->comm);
    parsing(msh);
    msh->envc = env;
    tree_make(msh, env);
    env = msh->envc;
    return 0;
}
