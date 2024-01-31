/*
** EPITECH PROJECT, 2022
** B-PSU-100-PAR-1-1-minishell-damian.gil
** File description:
** minishell
*/

#ifndef _MINISHELL_H_
    #define _MINISHELL_H_

    #include <stdio.h>
    #include <unistd.h>
    #include <sys/types.h>
    #include <stdlib.h>
    #include "mysh.h"
    #include <sys/wait.h>
    #include <string.h>
    #include <fcntl.h>
    #include <signal.h>
    #include "ll.h"
    #include <stdbool.h>

    typedef struct tree {
        int start;
        int end;
        int prio;
        int lowest;
        int pos_prio ;
    } tree_t;

    typedef struct minish {
        int run;
        int exit;
        char *command;
        char *true_command;
        char **comm;
        int count;
        int status;
        char *old_cd;
        char **envc;
        tree_t tree;
    } minish_t;


    void my_putchar(char c);

    int my_strlen(char const *str);

    char **my_str_to_word_array(char const *str, char delim);

    int fetch_delim(char const *str, char delimiteur);

    int malloc_that(char *str, char delimiteur, int send_it);

    int my_strlen(char const *str);

    void my_putstr(char const *str);

    char *my_strcat(char *dest, char const *src);

    int my_array_len(char **arr);

    char *my_strcpy(char *dest, char const *src);

    int check_exit(minish_t *msh);

    int check_perms_loop(char *path, minish_t *msh, char **env);

    void check_perms(char *line, minish_t *msh, char **env);

    void check_env_next(int count, minish_t  *msh, char **env);

    void check_env(minish_t *msh, char **env);

    int word_len(char const *str, char delim, int i);

    int delim_last(char const *str, char delim);

    int delim_count(char const *str, char delim);

    int my_env(minish_t *msh);

    char **alloc(char const *str, char delim, int last_delim);

    int my_strncmp(char const *s1, char const *s2, int n);

    int my_cd(minish_t *msh, char **env);

    int execute_com(char *exec, int check, minish_t *msh, char **env);

    int exit_msh(minish_t *msh);

    void signl(int sig);

    char *my_strdup(char const *src);

    void call(minish_t *msh, char **env);

    char **my_str_to_array(char *str, char delimiteur, char delim);

    int my_count_char(char const *str, char d);

    void delete_elem(char **comm, unsigned int i);

    void delete_empty(char **comm);

    char *frees(size_t size);

    void my_unsetenv(char **comm, char **env);

    char **my_setenv(minish_t *msh, char **comm, char **env);

    void setenv_short(char **comm, char **env, int i);

    void parsing(minish_t *msh);

    int my_strcmp(char const *s1, char const *s2);

    char *my_strncpy(char *dest, char const *src, int n);

    char *my_strndup(char const *src, int n);

    void my_show_word_array(char **arr);

    int parsed(minish_t *msh, char **temp, int list[4]);

    int another_parsing(minish_t *msh, char **temp, int list[4]);

    int next_parsed(minish_t *msh, char **temp, int list[4]);

    int empty_character(minish_t *msh, char **env);

    void tree_make(minish_t *msh, char **env);

    int recup_elem(char *str);

    char **separate(char **arr, int start, int end);

    void execute_tree(minish_t *msh, char **env, node_t *node);

    void make_pipe(int list[3]);

    void execute_pipe(int list[3]);

    void last_execute(int list[3]);

    int my_write(char **right);

    int append(char **right);

    int my_read(char **right);

    int my_grep(char **right);

    int my_isalpha(char c);

    void handle_access_error(char *path);

    bool verify_char(char *comm);

    char **error_env(char **comm, char **env, minish_t *msh);

#endif
