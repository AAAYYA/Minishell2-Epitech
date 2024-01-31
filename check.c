/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-damian.gil
** File description:
** check
*/

#include "includes/mysh.h"
#include <errno.h>

int check_perms_loop(char *path, minish_t *msh, char **env)
{
    int check = 0;
    int i = 0;
    msh->true_command = msh->comm[0];
    char *exec = malloc(sizeof(char) * (my_strlen(path)
    + my_strlen(msh->true_command) + 2));
    my_strcpy(exec, path);
    exec[my_strlen(path) + 1] = '\0';
    exec[my_strlen(path)] = '/';
    my_strcat(exec, msh->true_command);
    check = access(exec, X_OK);
    if (check == 0) {
        i++;
        execute_com(exec, check, msh, msh->envc);
        return check;
    } else
        return check;
}

void check_perms(char *line, minish_t *msh, char **env)
{
    int check = -1;
    int i = 0;
    char **arr = my_str_to_word_array(&line[5], ':');
    for (i = 0; arr[i] != NULL && check != 0; i++) {
        check = check_perms_loop(arr[i], msh, msh->envc);
    }
    if (check != 0) {
        write(2, msh->comm[0], my_strlen(msh->comm[0]));
        write(2, ": Command not found.\n", 22);
        msh->status = 1;
    }
}

void check_env_next(int count, minish_t *msh, char **env)
{
    if (count >= my_array_len(env))
        return;
    if (!my_strncmp(env[count], "PATH", 4))
        check_perms(env[count], msh, msh->envc);
}

int special_case(minish_t *msh, char **env)
{
    msh->envc = env;
    if (!(my_strncmp(msh->comm[0], "env", 3))) {
        my_env(msh);
        return 1;
    }
    if (!(my_strncmp(msh->comm[0], "cd", 2))) {
        call(msh, msh->envc);
        return 1;
    }
    if (!(my_strncmp(msh->comm[0], "exit", 4)))
        exit_msh(msh);
    if (!(my_strncmp(msh->comm[0], "setenv", 6))) {
        msh->envc = my_setenv(msh, msh->comm, msh->envc);
        return 1;
    }
    if (!(my_strncmp(msh->comm[0], "unsetenv", 8))) {
        my_unsetenv(msh->comm, msh->envc);
        return 1;
    }
    return 0;
}

void check_env(minish_t *msh, char **env)
{
    int count = 0;
    if (special_case(msh, msh->envc) == 1)
        return;
    if (access(msh->comm[0], X_OK) == 0) {
        execute_com(msh->comm[0], 0, msh, msh->envc);
        return;
    }
    for (count = 0; msh->envc[count] != NULL; count++) {
        if (my_strlen(msh->envc[count]) > 4) {
            check_env_next(count, msh, msh->envc);
        }
    }
}
