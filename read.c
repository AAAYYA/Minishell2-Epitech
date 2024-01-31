/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** read
*/

#include "includes/mysh.h"
#include "includes/ll.h"

int my_read(char **right)
{
    int i = 0;
    int fd = -1;
    int dupped = 0;

    for (; right[i] != NULL; i++);
    if (i < 1)
        return 84;
    fd = open(right[1 - 1], O_RDONLY);
    dupped = dup(STDIN_FILENO);
    dup2(fd, STDIN_FILENO);
    close(fd);
    return dupped;
}
