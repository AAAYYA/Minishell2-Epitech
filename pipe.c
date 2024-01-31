/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** pipe
*/

#include "includes/mysh.h"
#include "includes/ll.h"

void last_execute(int list[3])
{
    dup2(list[1], STDIN_FILENO);
    close(list[1]);
}

void execute_pipe(int list[3])
{
    dup2(list[2], STDIN_FILENO);
    dup2(list[0], STDOUT_FILENO);
    close(list[0]);
    close(list[2]);
    list[2] = -1;
}

void make_pipe(int list[3])
{
    int pipe1[2];

    if (pipe(pipe1) < 0) {
        my_putstr("Error: Failed to create pipes.\n");
        exit(1);
    }
    list[0] = dup(STDOUT_FILENO);
    list[1] = dup(STDIN_FILENO);
    list[2] = pipe1[0];
    dup2(pipe1[1], STDOUT_FILENO);
    close(pipe1[1]);
}
