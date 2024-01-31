/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-bsminishell1-damian.gil
** File description:
** my_exec
*/

#include "includes/mysh.h"
#include <errno.h>
#include <stdio.h>

void catch_sig(void)
{
    int i = 0;

    for (i = 1; i < 17; i++) {
        signal(i, &signl);
    }
}

int execute_com(char *exec, int check, minish_t *msh, char **env)
{
    pid_t pid = fork();

    if (pid == 0 && check == 0)
        execve(exec, msh->comm, env);
    if (pid == -1) {
        perror("fork");
        msh->status = 1;
    }
    pid = wait(&msh->status);
    if (pid == -1) {
        perror("fork");
        msh->status = 1;
    }
    if (WIFEXITED(msh->status))
        msh->status = WEXITSTATUS(msh->status);
    if (WIFSIGNALED(msh->status))
        msh->status = (WTERMSIG(msh->status) + 127);
    return 0;
}

int read_in(minish_t *msh, char **env)
{
    int get;
    size_t len = 0;
    while (msh->run) {
        if (isatty(0))
            write(1, ":> ", 4);
        catch_sig();
        get = getline(&msh->command, &len, stdin);
        if (get == -1)
            exit(msh->status);
        if (msh->command[get - 1] == '\n')
            msh->command[get - 1] = '\0';
        empty_character(msh, msh->envc);
    }
    return 0;
}

int main(int ac, char **av, char **env)
{
    int i = 0;
    char **envcp = malloc(sizeof(char *) * (my_array_len(env) + 1));
    minish_t *msh = malloc(sizeof(minish_t));

    msh->exit = 0;
    msh->run = 1;
    msh->command = NULL;
    msh->status = 0;
    for (i = 0; env[i] != NULL; i++) {
        envcp[i] = my_strdup(env[i]);
    }
    envcp[i] = NULL;
    msh->envc = envcp;
    read_in(msh, envcp);
    return msh->exit;
}
