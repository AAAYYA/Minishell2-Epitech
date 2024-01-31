/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** write
*/

#include "includes/mysh.h"
#include "includes/ll.h"
#include <fcntl.h>

int append(char **right)
{
    int i = 0;
    int fd = 0;
    int dupped = -1;

    for (; right[i] != NULL; i++);
    if (i < 1)
        return -1;
    fd = open(right[i - 1], O_WRONLY | O_CREAT | O_APPEND, 0777);
    dupped = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return dupped;
}

int my_write(char **right)
{
    int i = 0;
    int fd = 0;
    int dupped = -1;

    for (; right[i] != NULL; i++);
    if (i < 1)
        return -1;
    fd = open(right[i - 1], O_WRONLY | O_CREAT, 0777);
    dupped = dup(STDOUT_FILENO);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return dupped;
}
