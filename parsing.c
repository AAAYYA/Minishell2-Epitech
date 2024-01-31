/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** parsing
*/

#include "includes/mysh.h"

int args_count(minish_t *msh, int i, int j, int count)
{
    if (!my_strncmp(&(msh->comm[i][j]), "|", 1))
        count++;
    if (!my_strncmp(&(msh->comm[i][j]), ";", 1))
        count++;
    if (!my_strncmp(&(msh->comm[i][j]), "<", 1))
        count++;
    if (!my_strncmp(&(msh->comm[i][j]), ">", 1))
        count++;
    if (!my_strncmp(&(msh->comm[i][j]), ">>", 2))
        count--;
    return count;
}

int count_args(minish_t *msh)
{
    int count = 0;
    int i = 0;
    int j = 0;

    for (i = 0; msh->comm[i] != NULL; i++) {
        for (j = 0; msh->comm[i][j] != '\0' && msh->comm[i][j] != '\n'; j++) {
            count = args_count(msh, i, j, count);
        }
    }
    return count;
}

int parsed(minish_t *msh, char **temp, int list[4])
{
    if (!my_strncmp(&(msh->comm[list[0]][list[1]]), "|", 1)) {
        if (list[1] != 0) {
            temp[list[2]] = my_strndup(&(msh->comm[list[0]]
            [list[3]]), list[1] - list[3]);
            list[2]++;
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]][list[1]]), 1);
        list[2]++;
        list[3] = list[1] + 1;
    }
    another_parsing(msh, temp, list);
    next_parsed(msh, temp, list);
    return 0;
}

void parsing(minish_t *msh)
{
    char **temp = msh->comm;
    int list[4];
    list[2] = 0;
    list[3] = 0;
    temp = malloc((my_array_len(msh->comm) +
    count_args(msh) * 2 + 1) * sizeof(char *));
    for (int i = 0; i < count_args(msh) * 2 + 1 + my_array_len(msh->comm); i++)
        temp[i] = NULL;
    for (list[0] = 0; msh->comm[list[0]] != NULL; list[0]++) {
        list[3] = 0;
        for (list[1] = 0; msh->comm[list[0]][list[1]] != '\0'; list[1]++) {
            parsed(msh, temp, list);
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]]
        [list[3]]), list[1] - list[3]);
        list[2]++;
    }
    free(msh->comm);
    msh->comm = temp;
    delete_empty(msh->comm);
}
