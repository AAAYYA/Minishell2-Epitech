/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** cases_parsing
*/

#include "includes/mysh.h"
#include "includes/ll.h"

int parsed_third(minish_t *msh, char **temp, int list[4]);
int last_parsing(minish_t *msh, char **temp, int list[4]);
int parsing_fourth(minish_t *msh, char **temp, int list[4]);

int next_parsed(minish_t *msh, char **temp, int list[4])
{
    if (!my_strncmp(&(msh->comm[list[0]][list[1]]), "<<", 2)) {
        if (list[1] != 0) {
            temp[list[2]] = my_strndup(&(msh->comm[list[0]]
            [list[3]]), list[1] - list[3]);
            list[2]++;
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]][list[1]]), 2);
        list[2]++;
        list[1]++;
        list[3] = list[1] + 1;
        return 0;
    }
    parsed_third(msh, temp, list);
    return 0;
}

int parsed_third(minish_t *msh, char **temp, int list[4])
{
    if (!my_strncmp(&(msh->comm[list[0]][list[1]]), ">>", 2)) {
        if (list[1] != 0) {
            temp[list[2]] = my_strndup(&(msh->comm[list[0]]
            [list[3]]), list[1] - list[3]);
            list[2]++;
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]][list[1]]), 2);
        list[2]++;
        list[1]++;
        list[3] = list[1] + 1;
        return 0;
    }
    last_parsing(msh, temp, list);
    return 0;
}

int last_parsing(minish_t *msh, char **temp, int list[4])
{
    if (!my_strncmp(&(msh->comm[list[0]][list[1]]), ">", 1)) {
        if (list[1] != 0) {
            temp[list[2]] = my_strndup(&(msh->comm[list[0]]
            [list[3]]), list[1] - list[3]);
            list[2]++;
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]][list[1]]), 1);
        list[2]++;
        list[3] = list[1] + 1;
    }
    parsing_fourth(msh, temp, list);
    return 0;
}

int parsing_fourth(minish_t *msh, char **temp, int list[4])
{
    if (!my_strncmp(&(msh->comm[list[0]][list[1]]), "<", 1)) {
        if (list[1] != 0) {
            temp[list[2]] = my_strndup(&(msh->comm[list[0]]
            [list[3]]), list[1] - list[3]);
            list[2]++;
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]][list[1]]), 1);
        list[2]++;
        list[3] = list[1] + 1;
    }
    return 0;
}

int another_parsing(minish_t *msh, char **temp, int list[4])
{
    if (!my_strncmp(&(msh->comm[list[0]][list[1]]), ";", 1)) {
        if (list[1] != 0) {
            temp[list[2]] = my_strndup(&(msh->comm[list[0]]
            [list[3]]), list[1] - list[3]);
            list[2]++;
        }
        temp[list[2]] = my_strndup(&(msh->comm[list[0]][list[1]]), 1);
        list[2]++;
        list[3] = list[1] + 1;
    }
    return 0;
}
