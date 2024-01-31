/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell2-damian.gil
** File description:
** tree
*/

#include "includes/mysh.h"
#include "includes/ll.h"

struct node *recursive_tree(minish_t *msh, int start, int end);

struct node *fill_tree(struct node *left, struct node *right, enum type type)
{
    struct node *node = (struct node *)malloc(sizeof(struct node));
    if (node == NULL)
        return NULL;
    if (left == NULL)
        node->type_left = NONE;
    else {
        node->type_left = NODE;
        node->left.node = left;
    }
    if (right == NULL)
        node->type_right = NONE;
    else {
        node->type_right = NODE;
        node->right.node = right;
    }
    node->elem = type;
    return node;
}

int priority(minish_t *msh, int i)
{
    if (msh->comm == NULL)
        return 4;
    if (!my_strcmp(msh->comm[i], ";"))
        return 0;
    if (!my_strcmp(msh->comm[i], "|"))
        return 1;
    if (!my_strcmp(msh->comm[i], "<<"))
        return 2;
    if (!my_strcmp(msh->comm[i], ">>"))
        return 3;
    if (!my_strcmp(msh->comm[i], ">"))
        return 3;
    if (!my_strcmp(msh->comm[i], "<"))
        return 3;
    return 4;
}

struct node *finish_tree(minish_t *msh, int start, int end, int pos_prio)
{
    struct node *node;
    struct node *left;
    struct node *right;
    left = recursive_tree(msh, start, pos_prio - 1);
    right = recursive_tree(msh, pos_prio + 1, end);
    node = fill_tree(left, right, recup_elem(msh->comm[pos_prio]));
    if (node == NULL)
        return NULL;
    if (node->type_left == NONE) {
        node->type_left = COMMAND;
        node->left.command = separate(msh->comm, start, pos_prio - 1);
    }
    if (node->type_right == NONE) {
        node->type_right = COMMAND;
        node->right.command = separate(msh->comm, pos_prio + 1, end);
    }
    return node;
}

struct node *recursive_tree(minish_t *msh, int start, int end)
{
    msh->tree.prio = 0;
    msh->tree.lowest = 4;
    msh->tree.pos_prio = 0;

    for (int i = start; i < end; i++) {
        msh->tree.prio = priority(msh, i);
        if (msh->tree.prio <= msh->tree.lowest) {
            msh->tree.lowest = msh->tree.prio;
            msh->tree.pos_prio = i;
        }
    }
    if (msh->tree.lowest == 4)
        return NULL;
    return finish_tree(msh, start, end, msh->tree.pos_prio);
}

void tree_make(minish_t *msh, char **env)
{
    struct node *node = recursive_tree(msh, 0, my_array_len(msh->comm) - 1);
    if (node == NULL) {
        check_env(msh, msh->envc);
        return;
    }
    execute_tree(msh, env, node);
}
