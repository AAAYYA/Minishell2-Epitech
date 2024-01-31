/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** ll
*/

#ifndef LL_H_
    #define LL_H_

    #include "mysh.h"

enum type {
    NONE = 0,
    COMMAND,
    NODE,
    PIPE,
    READ,
    APPEND,
    WRITE,
    SEPARATOR,
    GREP,
};

typedef struct node node_t;

union element {
    char **command;
    node_t *node;
};

struct node {
    enum type type_left;
    enum type type_right;
    enum type elem;
    union element left;
    union element right;
};

#endif /* !LL_H_ */
