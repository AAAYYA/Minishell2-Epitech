/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** setenv
*/

#include "includes/mysh.h"
#include <stdbool.h>

void my_unsetenv_next(char *comm, char **env)
{
    int i = 0;

    for (i = 0; env[i] != NULL; i++) {
        if (!my_strncmp(env[i], comm, my_strlen(comm))) {
            delete_elem(env, i);
        }
    }
}

void my_unsetenv(char **comm, char **env)
{
    for (unsigned int i = 1; comm[i] != NULL; i++) {
        my_unsetenv_next(comm[i], env);
    }
}

void setenv_one_arg(char **comm, char **temp, int i)
{
    temp[i] = (char *)malloc(sizeof(char) *
        (my_strlen(comm[1]) + 1));
    temp[i] = my_strcpy(temp[i], comm[1]);
    temp[i] = my_strcat(temp[i], "=");
    temp[i + 1] = NULL;
}

char **my_setenvv(char **comm, char **env)
{
    int i = 0;
    char **temp;

    temp = (char **)malloc(sizeof(char *) * (my_array_len(env) + 2));
    for (i = 0; env[i] != NULL; i++) {
        temp[i] = env[i];
    }
    if (comm[2] == NULL)
        setenv_one_arg(comm, temp, i);
    else {
        temp[i] = (char *)malloc(sizeof(char) *
        (my_strlen(comm[1]) + my_strlen(comm[2]) + 2));
        temp[i] = my_strcpy(temp[i], comm[1]);
        temp[i] = my_strcat(temp[i], "=");
        temp[i] = my_strcat(temp[i], comm[2]);
    }
    temp[i + 1] = NULL;
    free(env);
    return temp;
}

char **my_setenv(minish_t *msh, char **comm, char **env)
{
    if (error_env(comm, env, msh) != NULL)
        return env;
    for (int i = 0; env[i] != NULL; i++) {
        if (!my_strncmp(env[i], comm[1], my_strlen(comm[1]) - 1)) {
            free(env[i]);
            env[i] = (char *)malloc(sizeof(char) *
            (my_strlen(comm[1]) + my_strlen(comm[2]) + 2));
            env[i] = my_strcpy(env[i], comm[1]);
            env[i] = my_strcat(env[i], "=");
            setenv_short(comm, env, i);
            return env;
        }
    }
    return my_setenvv(comm, env);
}
