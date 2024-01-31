/*
** EPITECH PROJECT, 2022
** BSQ
** File description:
** proto
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "includes/mysh.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}

void my_show_array(char **array, char d)
{
    int t_len = 0;
    while (array[t_len] != NULL) {
        t_len++;
    }
    for (int a = 0; a < t_len; a++) {
        my_putstr(array[a]);
        if (a != t_len - 1)
            my_putchar(d);
    }
    my_putchar('\n');
}

int my_strlen(char const *str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    for (i = 0; str[i] != '\0'; i++);
    return i;
}

void signl(int sig)
{
    my_putchar('\n');
    write(1, ":> ", 4);
}
