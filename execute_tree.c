/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** execute_tree
*/

#include "includes/mysh.h"
#include "includes/ll.h"

void execute_tree_second(minish_t *msh, char **env, node_t *node, int list[3])
{
    if ((node->elem == READ || node->elem == GREP) && list[2] != -1) {
        dup2(list[2], STDIN_FILENO);
        close(list[2]);
    }
    if ((node->elem == WRITE || node->elem == APPEND) && list[2] != -1) {
        dup2(list[2], STDOUT_FILENO);
        close(list[2]);
    }
    if (node->elem == PIPE) {
        execute_pipe(list);
    }
    if (node->type_right == NODE && list[2] == -1)
        execute_tree(msh, env, node->right.node);
    if (node->type_right == COMMAND && list[2] == -1) {
        free(msh->comm);
        msh->comm = node->right.command;
        check_env(msh, msh->envc);
    }
    if (node->elem == PIPE)
        last_execute(list);
}

void execute_tree(minish_t *msh, char **env, node_t *node)
{
    int list[3];
    list[2] = -1;
    if (node->elem == GREP && node->type_right == COMMAND)
        list[2] = my_grep(node->right.command);
    if (node->elem == READ && node->type_right == COMMAND)
        list[2] = my_read(node->right.command);
    if (node->elem == WRITE && node->type_right == COMMAND)
        list[2] = my_write(node->right.command);
    if (node->elem == APPEND && node->type_right == COMMAND)
        list[2] = append(node->right.command);
    if (node->elem == PIPE)
        make_pipe(list);
    if (node->type_left == NODE)
        execute_tree(msh, env, node->left.node);
    if (node->type_left == COMMAND) {
        free(msh->comm);
        msh->comm = node->left.command;
        check_env(msh, msh->envc);
    }
    execute_tree_second(msh, env, node, list);
}
