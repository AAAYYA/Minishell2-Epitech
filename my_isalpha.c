/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** my_isalpha
*/

#include "includes/mysh.h"
#include <stdbool.h>

int my_isdigit(char c)
{
    if (c >= '0' && c <= '9')
        return 1;
    else
        return 0;
}

int my_isalpha(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return 1;
    else
        return 0;
}

bool verify_char(char *comm)
{
    int i = 0;

    for (i = 0; comm[i] != '\0' && comm[i] != '\n'; i++) {
        if (!my_isalpha(comm[i]) && !my_isdigit(comm[i]))
            return false;
    }
    return true;
}

char **error_env(char **comm, char **env, minish_t *msh)
{
    if (comm[1] == NULL) {
        my_env(msh);
        return env;
    }
    if (my_isdigit(comm[1][0]))
        write(2, "The variable name must start with a letter\n", 44);
    if (verify_char(comm[1]) == false) {
        write(2, "The variable name must contain "
        "alphanumeric characters.\n", 57);
        return env;
    }
    return NULL;
}
