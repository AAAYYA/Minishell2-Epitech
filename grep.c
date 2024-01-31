/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** grep
*/

#include "includes/mysh.h"
#include "includes/ll.h"
#include <stdio.h>
#include <unistd.h>

void loop(char **right, char *str, ssize_t *n, int pipe1[2])
{
    size_t j = 0;
    write(1, "? ", 2);
    n[0] = getline(&str, &j, stdin);
    if (str != NULL) {
        if (str[n[0] - 1] == '\n')
            str[n[0] - 1] = '\0';
        if (!my_strcmp(str, right[0])) {
            n[0] = -1;
        } else {
            j = n[0];
            write(pipe1[1], str, j);
            write(pipe1[1], "\n", 1);
        }
        free(str);
        str = NULL;
    }
}

int my_grep(char **right)
{
    int pipe1[2];
    int dupped = 0;
    ssize_t n = 0;
    char *str = NULL;

    if (pipe(pipe1) < 0)
        return 84;
    while (n != -1) {
        loop(right, str, &n, pipe1);
    }
    dupped = dup(STDIN_FILENO);
    dup2(pipe1[0], STDIN_FILENO);
    close(pipe1[0]);
    close(pipe1[1]);
    return dupped;
}
